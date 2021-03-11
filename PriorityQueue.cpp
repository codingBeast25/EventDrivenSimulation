/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: PriorityQueue implementation
*/

#include <iostream>
#include <string>
#include "ListItem.h"
#include "Node.h"
#include "PriorityQueue.h"
#include "Event.h"

//constructor
PriorityQueue::PriorityQueue() : top(nullptr), size(0) {}

//Adds element to priority queue according to its priority
void PriorityQueue::enqueue(Event *item)
{
    Node *temp = new Node(item, nullptr);
    Node *curr; //current node pointer
    Node *prev;

    //if item to be inserted on first location
    if (top == nullptr || item->compareTo(top->getItem()) == 1)
    {
        temp->setNext(top);
        top = temp;
    }
    else
    {
        curr = top;
        //else find a location where it will go
        while (curr->getNext() != nullptr && (item->compareTo(curr->getNext()->getItem()) == 0))
        {
            curr = curr->getNext();
        }

        temp->setNext(curr->getNext());
        curr->setNext(temp);
    }
    size++;
}

//remove the top of queue and return the item
ListItem *PriorityQueue::dequeue()
{
    ListItem *maxPriority = nullptr;
    Node *curr = top;
    if (curr != nullptr)
    {
        maxPriority = curr->getItem();
        //if queue is empty
        if (top->getNext() == nullptr)
        {
            top = nullptr;
        }
        else
        {
            top = top->getNext();
        }
        delete (curr);
        size--;
    }
    return maxPriority;
}

//checks if queue is empty or not
bool PriorityQueue::isEmpty()
{
    return size == 0;
}

//returns the top item
ListItem *PriorityQueue::getTop()
{
    return (top->getItem());
}

//returns size
int PriorityQueue::getSize()
{
    return this->size;
}
PriorityQueue::~PriorityQueue() {}