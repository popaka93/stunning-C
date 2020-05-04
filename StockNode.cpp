#include "StockNode.h"
#include "Cart.h"

StockNode::StockNode() {
    stk=StockDb();
    next= nullptr;
    prev=nullptr;
    head = nullptr;
    tail = nullptr;
    length =0;
}

StockDb StockNode::getStock()
{
    return stk;
}
StockNode* StockNode::getNext()
{
    return next;
}

void StockNode::setNext(StockNode* n)
{
    next=n;
}
StockNode* StockNode::getPrev()
{
    return prev;
}
void StockNode::setPrev(StockNode* p)
{
    prev=p;
}


void StockNode::load(string file){
    ifstream inFile;
    ofstream outFile;
    inFile.open(file.c_str());
    outFile.open("StockDbUpdated.txt");
    StockDb tmp =StockDb();
    if(inFile.fail()){
        cout << "file is not found" <<endl;
        system("pause");
        exit(1);
    }else{cout<<"File loaded";}
    while(!inFile.eof()){
        StockNode *sp = new StockNode();
        inFile >> *sp;
        insert_back(sp);
        tmp =sp->getStock();
        outFile<<tmp;
    }
    inFile.close();
    outFile.close();
    cout<<"File Saved!"<<endl;
}

void StockNode::insert_back(StockNode *p)
{
    if (length==0)
    {
        p->setNext(nullptr);
        p->setPrev(nullptr);
        head = tail = p;
        length++;
        return;
    }
    p->setPrev(tail);
    tail->setNext(p);
    p->setNext(nullptr);
    tail=p;
    length++;
}


istream& operator>>(istream& in, StockNode& s){
    StockDb tmp;
    int sym;
    string name="";
    double price=0;
    int qty = 0;
    in>>sym>>name>>price>>qty;
    tmp.setSerial(sym); tmp.setItemName(name); tmp.setPrice(price); tmp.setQty(qty);
    s.stk=tmp;
    return in;
}

int StockNode::getSerial(int index){
    Cart goods;
    StockNode *current=head;
    StockDb tmp = current->getStock();
    while(current!=nullptr){
        if (current->getStock().getSerial() ==index){
            return current->getStock().getSerial();
        }
        current=current->next;
    }
}
string StockNode::getItemName(int index){
    Cart goods;
    StockNode *current=head;
    StockDb tmp = current->getStock();
    while(current!=nullptr){
        if (current->getStock().getSerial() ==index){
            return current->getStock().getItemName();
        }
        current=current->next;
    }
}
double StockNode::getPrice(int index){
    Cart goods;
    StockNode *current=head;
    StockDb tmp = current->getStock();
    while(current!=nullptr){
        if (current->getStock().getSerial() ==index){
            return current->getStock().getPrice();
        }
        current=current->next;
    }
}

ostream &operator << (ostream& os,StockNode& s){
    for (StockNode* i=s.head;i!=nullptr;i=i->getNext()){
        StockDb tmp =i->getStock();
        cout<<tmp;
    }
    return os;
}
