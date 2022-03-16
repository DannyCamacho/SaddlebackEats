#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H

#include <QMainWindow>
#include "database.h"

using namespace std;

namespace Ui { class CustomTrip; }
class CustomTrip : public QMainWindow {
    Q_OBJECT

public:
    explicit CustomTrip(QWidget *parent = nullptr);
    ~CustomTrip();

private slots:

private:
    Ui::CustomTrip *ui; /**< customtrip's ui*/
};
#endif // CUSTOMTRIP_H
