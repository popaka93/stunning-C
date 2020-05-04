#include "StockDb.h"
#include <iostream>
#include <fstream>
using namespace std;

StockDb::StockDb() {
    serialNumber=0;
    itemName = "";
    itemPrice =0;
    quantity =0;
}
StockDb::StockDb(int serial,string name,double price,int qty){
    serialNumber = serial;
    itemName = name;
    itemPrice = price;
    quantity = qty;
}

int StockDb::getSerial() {return serialNumber;}
string StockDb::getItemName() {return itemName;}
double StockDb::getPrice() {return itemPrice;}
int StockDb::getQty() {return quantity;}

void StockDb::setSerial(int serial){serialNumber = serial;}
void StockDb::setItemName(string iName){itemName = iName;}
void StockDb::setPrice(double pr){itemPrice = pr;}
void StockDb::setQty (int qty){quantity = qty;}

void StockDb::operator=(const StockDb &s) {
    serialNumber = s.serialNumber;
    itemPrice = s.itemPrice;
    itemName = s.itemName;
    quantity = s.quantity;
}

bool operator<(const StockDb& s1, const StockDb& s2){
    return(s1.quantity<s2.quantity);
}

ostream& operator <<(ostream &os,StockDb& s){
    os<< s.getSerial()<<"\t\t"<<s.getItemName()<<"\t\t"<<s.getPrice()<<"\t\t"<<s.getQty();
    os<<endl;
    return os;
}