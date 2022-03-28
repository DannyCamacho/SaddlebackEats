#include "customtrip.h"
#include "ui_customtrip.h"
#include "mainwindow.h"

CustomTrip::CustomTrip(QWidget *parent): ui(new Ui::CustomTrip) {
    ui->setupUi(this);
};

CustomTrip::~CustomTrip() {
    delete ui;
}
