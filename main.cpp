#include <iostream>
#include <string>
#include "Cart.h"
#include "StockNode.h"
#include "StockDb.h"
using namespace std;

int main() {
    StockNode stk;
    StockDb temp;
    Cart goods;
    stk.load("StockDb.txt");

    cout<<stk;

    int qty;
    double subTotal{};
    string name;
    string phone;
    string address;

    cout << "Please enter Name: ";
    cin >> name;
    cout << "Phone Number: ";
    cin >> phone;
    cout << "Address: ";
    cin >> address;
    while (true) {
        int choice;
        cout << " What would you like to Purchase " << endl;
        cout << " 1. Oranges $1 each " << endl;
        cout << " 2. Bananas $0.40 each " << endl;
        cout << " 3. Tomatos $3 each " << endl;
        cout << " 4. Grapes $2.50 each " << endl;
        cout << " 5. Pears $1.50 each " << endl;
        cout << " 6. Lemons $0.50 each " << endl;
        cout << " 7. Modify Cart" << endl;
        cout << " 8. Check Stock" << endl;
        cout << " 9. Check out " << endl;
        cin >> choice;
        int i = 0;
        switch (choice) {
            case 1: {
                cout << " How many would you like to buy? " << endl;
                cin >> qty;
                stk.getNth(0);
                subTotal += temp.getPrice() * qty;
                i++;
                break;
            }
            case 2: {
                cout << "How many would you like to buy? " << endl;
                cin >> qty;
                if(temp.getSerial()==2222) {
                    subTotal += temp.getPrice() * qty;
                    goods.insert(temp.getSerial(), temp.getItemName(), temp.getPrice(), qty, i);

                }
                i++;
                break;
            }
            case 3: {
                cout << " How many would you like to buy? " << endl;
                cin >> qty;
                if(temp.getSerial()==3333) {
                    subTotal += temp.getPrice() * qty;
                    goods.insert(temp.getSerial(), temp.getItemName(), temp.getPrice(), qty, i);

                }
                i++;
                break;
            }
            case 4: {
                cout << " How many would you like to buy? " << endl;
                cin >> qty;
                if(temp.getSerial()==4444) {
                    subTotal += temp.getPrice() * qty;
                    goods.insert(temp.getSerial(), temp.getItemName(), temp.getPrice(), qty, i);
                }
                i++;
                break;
            }
            case 5: {
                cout << " How many would you like to buy? " << endl;
                cin >> qty;
                if(temp.getSerial()==5555) {
                    subTotal += temp.getPrice() * qty;
                    goods.insert(temp.getSerial(), temp.getItemName(), temp.getPrice(), qty, i);
                }
                i++;
                break;
            }
            case 6: {
                cout << " How many would you like to buy? " << endl;
                cin >> qty;
                if(temp.getSerial()==6666) {
                    subTotal += temp.getPrice() * qty;
                    goods.insert(temp.getSerial(), temp.getItemName(), temp.getPrice(), qty, i);
                }
                i++;
                break;
            }
            case 7: {
                string itemModifiedName;
                int modQty;
                goods.display(cout);
                cout << "Please choose which items you would like to modify item's quantity: " << endl;
                cin >> itemModifiedName;
                cout << "Please choose the modified quantity: " << endl;
                cin >> modQty;
                goods.modify(itemModifiedName, modQty);
                goods.display(cout);
                break;
            }
            case 8: {
                cout << stk;
                break;
            }
            case 9: {
                cout << "Welcome to SJSU Shopping Center" << endl;
                cout << "-------------------------------" << endl;
                cout << "Name: " << name << endl;
                cout << "Phone #: " << phone << endl;
                cout << "Adress: " << address << endl;
                cout << "-------------------------------" << endl;
                goods.display(cout);
                cout << "Your Total is: $" << subTotal << endl;
                system("pause");
                exit(0);
                default:
                    cout << "Invalid choice";
            }
        }
    }
}