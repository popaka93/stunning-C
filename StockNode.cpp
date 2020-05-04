#include "StockNode.h"
#include "StockDb.h"
#include "Cart.h"

StockNode::StockNode() {
    stk=StockDb();
    next= nullptr;
    prev=nullptr;
    head = nullptr;
    tail = nullptr;
    length =0;
}
StockNode::StockNode(StockNode* node)
{
    stk=node->getStock();
    next=node->getNext();
    prev=node->getPrev();
}
StockDb StockNode::getStock()
{
    return stk;
}
StockNode* StockNode::getNext()
{
    return next;
}
StockNode* StockNode::getHead()
{
    return head;
}
StockNode* StockNode::getTail()
{
    return tail;
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
void StockNode::setStock(StockDb s)
{
    stk=s;
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
void StockNode::getNth(int index){
    StockDb tmp;
    Cart goods;
    StockNode *current=head;
    int count =0;
    int i =0;
    while(current!=nullptr){
        if (count ==index){
            goods.insert(tmp.getSerial(),tmp.getItemName(),tmp.getPrice(),tmp.getQty(),i);
            i++;
        }
        count++;
        current=current->next;
    }
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

ostream &operator << (ostream& os,StockNode& s){
    for (StockNode* i=s.head;i!=nullptr;i=i->getNext()){
        StockDb tmp =i->getStock();
        cout<<tmp;
    }
    return os;
}
