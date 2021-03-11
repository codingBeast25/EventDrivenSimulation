/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: Queue implementation.
*/
#include "ParentQueue.h"
#include "ListItem.h"
#include "Node.h"

ParentQueue::ParentQueue() : front(nullptr), back(nullptr), size(0) {}

int ParentQueue::getSize() { return size; }

bool ParentQueue::isEmpty()
{
    return size == 0;
}

void ParentQueue::enqueue(ListItem *item) {}

ListItem *ParentQueue::dequeue()
{
    ListItem *theItem = nullptr;
    Node *curr = front;
    if (front != nullptr)
    {
        theItem = front->getItem();
        // special case: removing last item
        if (front == back)
        {
            front = back = nullptr;
        }
        else
        {
            front = front->getNext();
        }
        size--;
        delete (curr);
    }
    return theItem;
}

ListItem *ParentQueue::getTop()
{
    return front->getItem();
}