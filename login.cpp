#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

Login::Login(QWidget *parent) : QDialog(parent), ui(new Ui::Login) {
    ui->setupUi(this);
    connect(this, SIGNAL(sendMessage(QString)), parent, SLOT(receiveMessage(QString)));
}

Login::~Login() {
    delete ui;
}

void Login::on_pushButtonLogin_clicked() {
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    if (username == "admin" && password == "password") {
        emit sendMessage("Admin Logged in");
        hide();
        delete ui;
    } else QMessageBox::warning(this, "Login", "Incorrect username or password");
}

void Login::on_pushButtonCancel_clicked() {
    hide();
}
