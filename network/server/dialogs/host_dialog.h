#ifndef HOST_DIALOG_H
#define HOST_DIALOG_H

#include <QDialog>

namespace Ui {
class HostDialog;
}

class HostDialog : public QDialog {
    Q_OBJECT
public:
    QString nick;
    quint32 port;
    explicit HostDialog(QWidget *parent = nullptr);
    ~HostDialog();
private slots:
    void on_buttonBox_accepted();
private:
    Ui::HostDialog *ui;
};

#endif // HOST_DIALOG_H
