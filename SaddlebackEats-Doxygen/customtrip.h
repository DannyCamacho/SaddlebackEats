#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H

#include <QMainWindow>
#include "database.h"

using namespace std;

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
     *  sets up ui
     */
    explicit CustomTrip(QWidget *parent = nullptr);

    /*! Destructor
     *
     *  deletes ui
     */
    ~CustomTrip();

private slots:

private:

    /*! @var Ui::CustomTrip *ui
     *  customtrip's ui
     */
    Ui::CustomTrip *ui;
};
#endif // CUSTOMTRIP_H
