#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    QString get_nick() const;
    QString get_host() const;
    quint16 get_port() const;
    ~Dialog();

private slots:
    void on_connect_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::Dialog *ui;
    QSettings *settings;
    QString nick;
    QString host;
    quint16 port;
};

#endif // DIALOG_H
