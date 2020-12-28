#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QShortcut>
#include <QTextCursor>
#include <QString>
#include <QSystemTrayIcon>
#include <QTextCodec>

#include "headers/info.h"
#include "headers/QtServer.h"
#include "headers/dialog.h"
#include "headers/dialog_creating_server.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QString nick;
    QTcpSocket *socket;
    QtServer *server;
    void readingText();
    void connectionToServer(QString host, quint16 port, QString nick);
    void setupConnection();

private slots:
    void on_send_btn_clicked();
    void on_save_btn_clicked();
    void show_info();
    void connection_failure();

private:
    Ui::Widget *ui;
    QShortcut *shortcutSave;
    QShortcut *shortcutInfo;
    QSystemTrayIcon* tray;
};

#endif // WIDGET_H
