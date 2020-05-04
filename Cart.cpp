#include "Cart.h"
using namespace std;

Cart::Cart() {
    has_a = nullptr;
    mySize = 0;
}

void Cart::display(ostream &os) const {
    nodePtr current = has_a;
    cout << "Serial Number \t\t Item Name \t\t Price \t\t Quantity" << endl;
    while (current != nullptr) {
        os << current->serialNum << "\t\t\t\t " << current->itemName << "\t\t\t " << current->price << "\t\t\t"
           << current->quantity << endl;
        current = current->next;
    }
}

void Cart::modify(string itemModName, int qty) {
    if (has_a != nullptr) {
        nodePtr current = has_a;
        while (current != nullptr) {
            if (current->itemName == itemModName) current->quantity = qty;
            current = current->next;
        }
    }
}

void Cart::insert(int serial, string name, double pr, int qty, int index) {
    if (index == 0) {
        nodePtr newNode = new Node;
        newNode->serialNum = serial;
        newNode->itemName = name;
        newNode->price = pr;
        newNode->quantity = qty;
        newNode->next = has_a;
        has_a = newNode;
        mySize++;
    } else if (index > 0 && index <= (mySize + 1)) {
        nodePtr current = has_a;
        for (int i = 0; i < index - 1; i++) current = current->next;
        nodePtr newNode = new Node;
        newNode->serialNum = serial;
        newNode->itemName = name;
        newNode->price = pr;
        newNode->quantity = qty;
        newNode->next = current->next;
        current->next = newNode;
        mySize++;
    }
}

Cart::~Cart() {

}
