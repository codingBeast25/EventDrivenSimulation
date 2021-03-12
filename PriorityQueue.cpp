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
PriorityQueue::PriorityQueue() : ParentQueue() {}

//Adds element to priority queue according to its priority
void PriorityQueue::enqueue(ListItem *item)
{
    Node *temp = new Node(item, nullptr);
    Node *curr; //current node pointer
    Node *prev;

    //if item to be inserted on first location
    if (front == nullptr || item->compareTo(front->getItem()) == 1)
    {
        temp->setNext(front);
        front = temp;
    }
    else
    {
        curr = front;
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

PriorityQueue::~PriorityQueue() {}