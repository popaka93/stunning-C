#ifndef STOCKNODE_H_
#define STOCKNODE_H_

#include <iostream>
#include <fstream>
#include "StockDb.h"
class StockNode
{
public:
    StockNode();
    StockNode(StockNode* node);
    friend istream& operator>>(istream& in, StockNode& s);
    friend ostream& operator <<(ostream& os, StockNode& s);
    StockDb getStock();
    StockNode* getNext();
    StockNode* getPrev();
    StockNode* getHead();
    StockNode *getTail();
    void setStock(StockDb s);
    void setNext(StockNode* n);
    void setPrev(StockNode* p);
    void load(string);
    void insert_back(StockNode *p);
    void getNth(int index);
private:
    StockDb stk;
    StockNode* head;
    StockNode*tail;
    StockNode* next;
    StockNode* prev;
    int length;



};
#endif