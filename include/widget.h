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
#include "info.h"
#include "QtServer.h"
#include "dialog.h"
#include "dialog_creating_server.h"

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
    void reading_text();
    void connection_to_server(QString host, quint16 port, QString nick);
    void setup_connection();

private slots:
    void on_send_btn_clicked();
    void on_save_btn_clicked();
    void show_info();
    void connection_failure();

private:
    Ui::Widget *ui;
    QShortcut *shortcut_save;
    QShortcut *shortcut_info;
    QSystemTrayIcon* tray;
};
#endif // WIDGET_H
