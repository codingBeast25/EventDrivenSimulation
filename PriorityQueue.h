/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: priority queue defination.
*/

#pragma once

class Node;
class ListItem;
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

    //get the queue size
    int getSize();

    //default destructor
    ~PriorityQueue();
};