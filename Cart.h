#ifndef FINALPROJECT_CART_H
#define FINALPROJECT_CART_H

#include <iostream>

using namespace std;

class Cart {
private:
    class Node {
    public:
        int serialNum;
        string itemName;
        double price;
        int quantity;
        Node *next;
        Node() : serialNum(), next(nullptr) {}
    };
    typedef Node *nodePtr;
public:
    Cart();
    ~Cart();
    void insert(int serial, string name, double pr, int qty, int index);
    void modify(string itemModName, int qty);
    void display(ostream &os) const;
private:
    nodePtr has_a;
    int mySize;
};


#endif //FINALPROJECT_CART_H
