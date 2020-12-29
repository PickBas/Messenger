#include "headers/info.h"
#include "ui_info.h"

info::info(QWidget *parent) : QDialog(parent), ui(new Ui::info){
    ui->setupUi(this);
}

info::~info(){
    delete ui;
}

void info::on_close_btn_clicked(){
    QDialog::reject();
}
