#ifndef FINALPROJECT_STOCKDB_H
#define FINALPROJECT_STOCKDB_H
#include <iostream>
using namespace std;

class StockDb {
public:
    StockDb();
    StockDb(int serial,string itName,double pr, int qty);
    void operator =(const StockDb & s);
    friend bool operator <(const StockDb& s1, const StockDb &s2);
    friend ostream &operator<<(ostream& os,StockDb& s);

    int getSerial();
    string getItemName();
    double getPrice();
    int getQty();

    void setSerial(int serial);
    void setItemName(string iName);
    void setPrice(double pr);
    void setQty (int qty);

private:
    int serialNumber;
    string itemName;
    double itemPrice;
    int quantity;
};
#endif