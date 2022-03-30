#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H

#include <QMainWindow>
#include <QMessageBox>
#include <vector>
#include "database.h"

namespace Ui { class CustomTrip; }

/*! \class CustomTrip
 *  \brief Allows the user to plan a custom trip
 *  This class allows a user to pick which restaurants to go to during a trip
 *
 */
class CustomTrip : public QMainWindow {
    Q_OBJECT

public:
    /*! Constructor
     *
     *  Constructor used to initialize SQLQueryModels tripModel and routeModel, set the starting location to 0 (Saddleback College), initialize the location distances, run the recursive method, and update both tablesviews.
     */
    explicit CustomTrip(QWidget *parent = nullptr);

    /*! Destructor
     *
     *  Destructor used to delete SQLQueryModels tripModel and routeModel and the CustomTrip UI.
     */
    ~CustomTrip();

private slots:

    /*! @fn void initializeDistances()
     *
     *  Method used to initialize the comboBox with all restaurant entries, update the 2d distances array used in the recursive function, and update the cart quantity amount.
     */
    void initializeDistances();

    /*! @fn void calculateTrip(int start)
     *  Recursive method used to find the closest location from the current location, the base case being when start is set to -1.
     *  @param int start
     */
    void calculateTrip(int start);

    /*! @fn void tableViewUpdate()
     *
     *  Method used to update the restaurants included in the custom trip, the recursive method (calculateTrip) is then called.
     */
    void tableViewUpdate();

    /*! @fn void updateTrip()
     *
     * Method used to update the two tables, updates the location selection pool based off restaurants currently found within the route. the total distance is determined by summing all distances found within the route tableview.
     */
    void updateTrip();

    /*! @fn void on_pushButton_6_clicked()
     *
     *  Return to Main Menu Button: Clears exising route table and hides and deletes CustomTrip UI and creates and shows a new MainWindow UI.
     */
    void on_pushButton_6_clicked();

    /*! @fn void on_tripTableView_clicked(const QModelIndex &index)
     *
     *  Updates the name member when a restaurant is selected. index is the specific row selected of the tableview. Clears the route tableview selection when a trip tableview item is selected.
     *  @param const QModelIndex &index
     */
    void on_tripTableView_clicked(const QModelIndex &index);

    /*! @fn void on_routeTableView_clicked(const QModelIndex &index)
     *
     *  Updates the name member when a restaurant is selected. index is the specific row selected of the tableview. Clears the trip tableview selection when a route tableview item is selected.
     *  @param const QModelIndex &index
     */
    void on_routeTableView_clicked(const QModelIndex &index);

    /*! @fn void on_pushButton_9_clicked()
     *
     *  Add Button: Adds the selected restaurant from the trip tableview to the route tableview, if a trip tableview entry is not selected, a warning message is displayed to the user. The new efficient trip is then calculated and displayed.
     */
    void on_pushButton_9_clicked();

    /*! @fn void on_pushButton_10_clicked()
     *
     *  Remove Button: Removes the selected restaurant from the route tableview and adds it to the trip tableview, if a route tableview entry is not selected, a warning message is displayed to the user. The new efficient trip is then calculated and displayed.
     */
    void on_pushButton_10_clicked();

    /*! @fn void on_restComboBox_currentTextChanged(const QString &arg1)
     *
     *  ComboBox Item Selected: Updates the starting location based off the selected comboBox item selected. The trip is then recalculated and displayed to the user.
     *  @param const QString &arg1
     */
    void on_restComboBox_currentTextChanged(const QString &arg1);

    /*! @fn void on_pushButton_3_clicked()
     *
     *  Domino's Pizza Button: Updates the starting location to Domino's and updates the comboBox item to display Domino's Pizza. The new efficient trip is then calculated and displayed.
     */
    void on_pushButton_3_clicked();

    /*! @fn void on_pushButton_2_clicked()
     *
     *  Place Order Button: Changes button text to Processing... and waits for 2 seconds to simulate processing a payment. The shopping cart table is then reset and a confirmation popup message is displayed to the user. If the cart is currently empty, a warning popup is displayed to the user.
     */
    void on_pushButton_2_clicked();

    /*! @fn void on_cartButton_clicked()
     *
     *  Shopping Cart Button: Clears exising route table and hides and deletes CustomTrip UI and creates and shows a new ShoppingCart UI.
     */
    void on_cartButton_clicked();

private:
    /*! @var Ui::CustomTrip *ui
     *  customtrip's ui
     */
    Ui::CustomTrip *ui;

    /*! @var QSqlQueryModel* tripModel
     *  Holds values for SQL's trips
     */
    QSqlQueryModel* tripModel;

    /*! @var QSqlQueryModel* routeModel
     *  Holds values for SQL's route
     */
    QSqlQueryModel* routeModel;

    /*! @var std::vector<int> order
     *  A vector that determines the order of the routes
     */
    std::vector<int> order;

    /*! @var QString name
     *  Qstring for a restaurant
     */
    QString name;

    /*! @var bool isAvailable
     *  boolean array
     */
    bool isAvailable[20];

    /*! @var double d
     *  two-dimensional double array
     */
    double d[20][20];

    /*! @var int start
     *  The starting point
     */
    int start;
};

#endif // CUSTOMTRIP_H
