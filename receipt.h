#ifndef RECEIPT_H
#define RECEIPT_H

#include <QMainWindow>
#include <QFont>
#include "database.h"

using namespace std;

namespace Ui {class receipt; }

class receipt : public QMainWindow
{
    Q_OBJECT

public:
    explicit receipt(QWidget *parent = nullptr);
    ~receipt();

private slots:
    void printReceipt();

private:
    Ui::receipt *ui;
    QSqlQueryModel *receiptModel;
};

#endif // RECEIPT_H
