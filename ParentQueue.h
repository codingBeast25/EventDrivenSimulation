/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: Parent class for priority queue and Queue
*/
#pragma once

class Node;
class ListItem;

class ParentQueue
{
private:
    Node *front;
    Node *back;
    int size;

public:
    ParentQueue();
    int getSize();
    bool isEmpty();
    virtual void enqueue(ListItem *item) = 0;
    ListItem *getTop();
    ListItem *dequeue();
}; // class Queue
