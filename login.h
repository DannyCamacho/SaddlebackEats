#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>

namespace Ui { class Login; }

class Login : public QDialog {
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void sendMessage(const QString &msg);

private slots:
    void on_pushButtonLogin_clicked();
    void on_pushButtonCancel_clicked();
    void on_lineEditPassword_returnPressed();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
