#include "headers/widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget){
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/pic/icon.ico"));

    ui->textEdit->setReadOnly(true);
    socket = new QTcpSocket(this);
    tray = new QSystemTrayIcon(this);

    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    tray->setIcon(QIcon(":/pic/icon.ico"));
    tray->show();
    setupConnection();

    shortcutSave = new QShortcut(QKeySequence("Ctrl+s"), this);
    connect(shortcutSave, SIGNAL(activated()), this, SLOT(on_save_btn_clicked()));

    shortcutInfo = new QShortcut(QKeySequence("Ctrl+i"), this);
    connect(shortcutInfo, SIGNAL(activated()), this, SLOT(show_info()));

    connect(this->socket, &QTcpSocket::readyRead, [&](){
            this->readingText();
    });

}

Widget::~Widget(){
    delete ui;
    delete socket;
    delete server;
    delete shortcutSave;
    delete shortcutInfo;
    delete tray;
}

void Widget::readingText(){
    QTextStream text(socket);
    auto text_to_append = text.readAll();
    if (this->nick == text_to_append.left(nick.size()) && text_to_append[nick.size()] == ':'){
        ui->textEdit->setAlignment(Qt::AlignRight);
        ui->textEdit->append(text_to_append.mid(nick.size()+2, text_to_append.size() - 1) + "\n");
    } else {
        ui->textEdit->setAlignment(Qt::AlignLeft);
        ui->textEdit->append(text_to_append + "\n");
        if (this->isMinimized() || !this->isActiveWindow())
            tray->showMessage(text_to_append.mid(0, text_to_append.indexOf(':')), text_to_append.mid(text_to_append.indexOf(':') + 1,
                                                                                                 text_to_append.size()), QIcon(), 3000);
    }
}

void Widget::connectionToServer(QString host, quint16 port, QString nick){
    this->nick = nick;
    this->socket->connectToHost(host, port);
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(connection_failure()), Qt::DirectConnection);
    QTextStream text(socket);
    text << "User \"" << this->nick << "\" connected!";
    socket->flush();

}

void Widget::setupConnection(){
    qint8 reply = QMessageBox::question(this, "Connection", "Do you want to create your own server or connect to a server?",
                                        "Create", "Connect");
    if (reply == 1) {
        Dialog d(this);
        if (d.exec() == QDialog::Rejected)
            exit(1);
        connectionToServer(d.get_host(), d.get_port(), d.get_nick());
    } else {
        Dialog_creating_server d(this);
        if (d.exec() == Dialog_creating_server::Rejected)
            exit(1);
        server = new QtServer(this);

        if (!server->start_server(d.get_port())){
            QMessageBox::warning(this, "Error", "Server error: " + server->errorString(), "Close");
            exit(1);
        }
        else
            qDebug() << "Server started...\n";
        connectionToServer("127.0.0.1", d.get_port(), d.get_nick());
    }
}

void Widget::on_send_btn_clicked(){
    if(!ui->messege->text().isEmpty()){
        QTextStream text(socket);
        QString message = ui->messege->text();
        text << this->nick << ": " << message;
        socket->flush();
        ui->messege->clear();
    }
}

void Widget::on_save_btn_clicked(){
    auto text = ui->textEdit->toPlainText();
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    QTextStream output(&file);
    output << text;
    file.close();
}

void Widget::show_info(){
    info i(this);
    if(i.exec() == QDialog::Rejected)
        i.close();
}

void Widget::connection_failure(){
    qint8 reply = QMessageBox::warning(this, "Error", "Connection failed!", "Reconnect", "Close");
    if (reply == 1)
        exit(1);
    else
        setupConnection();

}
