#include <iostream>
#include <string>
#include "Cart.h"
#include "StockNode.h"

using namespace std;

int main() {
    StockNode stk;
    StockDb temp;
    Cart goods;
    stk.load("StockDb.txt");

    cout<<stk;
    cout << endl;

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
        cout << " 1. Orange $1.5 each " << endl;
        cout << " 2. Tomato $0.5 each " << endl;
        cout << " 3. Banana $2.5 each " << endl;
        cout << " 4. Pear $0.75 each " << endl;
        cout << " 5. Grapes $1.75 each " << endl;
        cout << " 6. Lemon $0.5 each " << endl;
        cout << " 7. WaterMelon $3.5 each " << endl;
        cout << " 8. Strawberry $2.3 each " << endl;
        cout << " 9. Modify Cart" << endl;
        cout << " 10. Check Stock" << endl;
        cout << " 11. Check out " << endl;
        cin >> choice;
        int i = 0;
        switch (choice) {
            case 1: {
                cout << " How many would you like to buy? " << endl;
                cin >> qty;
                goods.insert(stk.getSerial(111111), stk.getItemName(111111), stk.getPrice(111111), qty, i);
                subTotal += stk.getPrice(111111) * qty;
                i++;
                break;
            }
            case 2: {
                cout << "How many would you like to buy? " << endl;
                cin >> qty;
                    goods.insert(stk.getSerial(222222), stk.getItemName(222222), stk.getPrice(222222), qty, i);
                    subTotal += temp.getPrice() * qty;
                i++;
                break;
            }
            case 3: {
                cout << "How many would you like to buy? " << endl;
                cin >> qty;
                goods.insert(stk.getSerial(333333), stk.getItemName(333333), stk.getPrice(333333), qty, i);
                subTotal += temp.getPrice() * qty;
                i++;
                break;
            }
            case 4: {
                cout << "How many would you like to buy? " << endl;
                cin >> qty;
                goods.insert(stk.getSerial(444444), stk.getItemName(444444), stk.getPrice(444444), qty, i);
                subTotal += temp.getPrice() * qty;
                i++;
                break;
            }
            case 5: {
                cout << "How many would you like to buy? " << endl;
                cin >> qty;
                goods.insert(stk.getSerial(555555), stk.getItemName(555555), stk.getPrice(555555), qty, i);
                subTotal += stk.getPrice(555555) * qty;
                i++;
                break;
            }
            case 6: {
                cout << "How many would you like to buy? " << endl;
                cin >> qty;
                goods.insert(stk.getSerial(666666), stk.getItemName(666666), stk.getPrice(666666), qty, i);
                subTotal += stk.getPrice(666666) * qty;
                i++;
                break;
            }
            case 7: {
                cout << " How many would you like to buy? " << endl;
                cin >> qty;
                goods.insert(stk.getSerial(777777), stk.getItemName(777777), stk.getPrice(777777), qty, i);
                subTotal += stk.getPrice(777777) * qty;
                i++;
                break;
            }
            case 8: {
                cout << " How many would you like to buy? " << endl;
                cin >> qty;
                goods.insert(stk.getSerial(888888), stk.getItemName(888888), stk.getPrice(888888), qty, i);
                subTotal += stk.getPrice(888888) * qty;
                i++;
                break;
            }
            case 9: {
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
            case 10: {
                cout << stk;
                break;
            }
            case 11: {
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
