#include "customtrip.h"

//    bool isAvailable[20];
//    int order[20];
//    double d[20][20];

CustomTrip::CustomTrip() {
    for (int i = 0; i < 20; ++i) {
        order[i] = -1;
        isAvailable[i] = true;
        for (int k = 0; k < 20; ++k) {
            d[i][k] = 0;
        }
    }

    int i = 1;
    QSqlQuery query("SELECT * FROM restaurant");
    while (query.next()) {
        for (int k = 0; k < 20; ++ k) d[i][k] = query.value(k + 2).toDouble();
        d[0][i] = d[i][0];
        ++i;
    }

    for (int i = 11; i < 20; ++i) isAvailable[i] = false;
}

double CustomTrip::calculateTrip(int start) {
    order[0] = start;
    isAvailable[start] = false;
    int sIndex = 0;
    double sDist = 0.0;
    double totalDistance = 0.0;

    for (int i = 0; i < 20; ++i) {
        if (isAvailable[i]) {
            sIndex = i;
            totalDistance = sDist = d[i][start];
            order[1] = i;
            isAvailable[i] = false;
            break;
        }
    }

    for (int i = 0; i < 20; ++i) {
        if (isAvailable[i]) {
            if (d[i][start] < sDist) {
                isAvailable[sIndex] = true;
                order[1] = sIndex = i;
                isAvailable[i] = false;
                totalDistance = sDist = d[i][start];
                totalDistance += calculateTrip(i, 2);
                i = 0;
            }
        }
    }

    for (int i = 0; i < 20; ++i) {
            std::cout << order[i] << " ";
    }

    std::cout << "\n\n\n" << totalDistance;

    return totalDistance;
}

double CustomTrip::calculateTrip(int n, int o) {
    int sIndex = 0;
    double sDist = 0.0;
    double totalDistance = 0.0;

    for (int i = 0; i < 20; ++i) {
        if (isAvailable[i]) {
            sIndex = i;
            totalDistance = sDist = d[i][n];
            order[o] = i;
            isAvailable[i] = false;
            break;
        }
    }

    for (int i = 0; i < 20; ++i) {
        if (isAvailable[i]) {
            if (d[i][n] < sDist) {
                isAvailable[sIndex] = true;
                order[o] = sIndex = i;
                isAvailable[i] = false;
                totalDistance = sDist = d[i][n];
                totalDistance += calculateTrip(i, o + 1);
                i = 0;
            }
        }
    }
    return totalDistance;
}
