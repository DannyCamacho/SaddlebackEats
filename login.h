#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>

namespace Ui { class Login; }

/*! \class Login
 *  \brief Handles login to admin
 *  This class handles the ability to login as an admin to access the debug menu
 *  @see debugmenu.h
 */
class Login : public QDialog {
    Q_OBJECT

public:

    /*! Constructor
     *
     *  Sets up ui. connects to its parent
     *  @param QWidget parent
     */
    explicit Login(QWidget *parent = nullptr);

    /*! Destructor
     *
     *  deletes ui
     */
    ~Login();

signals:
    /*! @fn void sendMessage(const QString &msg)
     *
     *  @param const QString &msg
     */
    void sendMessage(const QString &msg);

private slots:

    /*! @fn void on_pushButtonLogin_clicked()
     *
     *  Checks username and password, then logs in if possible
     */
    void on_pushButtonLogin_clicked();

    /*! @fn void on_pushButtonCancel_clicked()
     *
     *   Cancels login
     */
    void on_pushButtonCancel_clicked();

private:

    /*! @var Ui::Login *ui
     *  Login's ui
     */
    Ui::Login *ui;
};

#endif // LOGIN_H
