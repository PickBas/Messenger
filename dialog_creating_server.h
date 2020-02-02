#ifndef DIALOG_CREATING_SERVER_H
#define DIALOG_CREATING_SERVER_H

#include <QDialog>

namespace Ui {
class Dialog_creating_server;
}

class Dialog_creating_server : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_creating_server(QWidget *parent = nullptr);
    QString get_nick() const;
    quint16 get_port() const;
    ~Dialog_creating_server();

private slots:
    void on_connect_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::Dialog_creating_server *ui;
    QString nick;
    quint16 port;
};

#endif // DIALOG_CREATING_SERVER_H
