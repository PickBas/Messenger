#include "host_dialog.h"
#include "ui_host_dialog.h"

HostDialog::HostDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HostDialog) {
    ui->setupUi(this);
}

HostDialog::~HostDialog()
{
    delete ui;
}

void HostDialog::on_buttonBox_accepted() {
    nick = ui->nickInput->text();
    port = ui->portInput->value();
    accept();
}

