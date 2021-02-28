

#pragma once

#include "Node.h"
#include "ListItem.h"
class Event;

using namespace std;

class PriorityQueue
{
private:
    Node *top;
    int size;

public:
    PriorityQueue(); //constructor

    //insert event accorind to priority
    void enqueue(Event *item);

    //remove with priority
    ListItem *dequeue();

    //check if empty
    bool isEmpty();

    //get the top item
    ListItem *getTop();

    //print the queue
    string print();

    //get the queue size
    int getSize();

    //default destructor
    ~PriorityQueue();
};