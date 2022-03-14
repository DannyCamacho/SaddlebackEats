#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H

#include "database.h"

class CustomTrip {
public:
    CustomTrip();
    double calculateTrip(int start);
    double calculateTrip(int n, int o);
private:
    bool isAvailable[20];
    int order[20];
    double d[20][20];
};
#endif // CUSTOMTRIP_H
