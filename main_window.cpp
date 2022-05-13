#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    serverManagement = new ServerManagement(this, ui->messageDisplayBox);
    fileManagement = nullptr;
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
}

MainWindow::~MainWindow() {
    delete ui;
    delete serverManagement;
    if (fileManagement != nullptr) {
        delete fileManagement;
    }
}

void MainWindow::on_actionConnect_triggered() {
    ConnectDialog* dialog = new ConnectDialog(this);
    if (dialog->exec() == 1) {
        serverManagement->connectToServer(dialog->nick,
                                          dialog->host,
                                          dialog->port);
    }
    delete dialog;
}

void MainWindow::on_actionHost_triggered() {
    HostDialog* dialog = new HostDialog(this);
    if (dialog->exec() == 1) {
        serverManagement->hostServer(dialog->nick, dialog->port);
    }
    delete dialog;
}


void MainWindow::on_sendMessageBtn_clicked() {
    if (ui->messageInput->text().isEmpty()) {
        return;
    }
    serverManagement->sendMessage(ui->messageInput->text());
    ui->messageInput->clear();
}


void MainWindow::on_actionSave_triggered() {
    auto text = ui->messageDisplayBox->toPlainText();
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    fileManagement = new FileManagement(fileName);
    fileManagement->saveMessagesToFile(text);
}

