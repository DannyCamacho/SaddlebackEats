#ifndef RESTAURANT_H
#define RESTAURANT_H

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;
/*\*/
//Note that this doxygen may be incorrect as I am inexperienced with it
/*\struct menuItem struct */

struct menuItem
{
    string itemName; /*\var itemName string variable */
    float itemPrice; /*\var itemPrice float variable*/
};

/*\class restaurant class */

class restaurant
{
    public:
            restaurant();
            ~restaurant();
    private:
            string restaurantName;      /*\var restaurantName string variable */
            int restaurantNumber;       /*\var restaurantNumber int variable*/
            vector<float> distanceList; /*\var distanceList float vector variable*/
            //Note that Saddleback's distance is index 0
            int menuCount;              /*\var menuCount int variable*/
            vector<menuItem> menuList;  /*\var menuList menuItem vector variable*/

};

#endif // RESTAURANT_H
