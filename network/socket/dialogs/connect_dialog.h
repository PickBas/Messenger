#ifndef CONNECT_DIALOG_H
#define CONNECT_DIALOG_H

#include <QDialog>

namespace Ui {
class ConnectDialog;
}

class ConnectDialog : public QDialog {
    Q_OBJECT
public:
    QString nick;
    QString host;
    quint16 port;
    explicit ConnectDialog(QWidget *parent = nullptr);
    ~ConnectDialog();
private slots:
    void on_buttonBox_accepted();
private:
    Ui::ConnectDialog *ui;
};

#endif // CONNECT_DIALOG_H
