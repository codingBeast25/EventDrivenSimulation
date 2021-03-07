

#include <iostream>
#include <string>
#include "ListItem.h"
#include "PriorityQueue.h"
#include "Event.h"

PriorityQueue::PriorityQueue() : top(nullptr), size(0) {}

void PriorityQueue::enqueue(Event *item)
{
    Node *temp = new Node(item, nullptr);
    Node *curr; //current node pointer
    Node *prev;

    if (top == nullptr || item->compareTo(dynamic_cast<ListItem *>(top->getItem())) == 1)
    {
        temp->setNext(top);
        top = temp;
    }
    else
    {
        curr = top;
        while (curr->getNext() != nullptr && (item->compareTo(dynamic_cast<ListItem *>(curr->getNext()->getItem())) == 0))
        {

            curr = curr->getNext();
        }

        temp->setNext(curr->getNext());
        curr->setNext(temp);

        /*
        prev = top;
        curr = top->getNext();
        while (prev->getNext() != nullptr)
        {
            if (item->compareTo(dynamic_cast<ListItem *>(curr->getItem())) == 1)
            {
                prev->setNext(temp);
                temp->setNext(curr);
            }
            prev = curr;
            curr = curr->getNext();
        }
        prev->setNext(temp);
        temp->setNext(curr);
        */
    }
    size++;
}

ListItem *PriorityQueue::dequeue()
{
    ListItem *maxPriority = nullptr;
    Node *curr = top;
    if (curr != nullptr)
    {
        maxPriority = dynamic_cast<ListItem *>(curr->getItem());

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

bool PriorityQueue::isEmpty()
{
    bool result = false;
    if (top == nullptr)
    {
        result = true;
    }
    return result;
}

ListItem *PriorityQueue::getTop()
{
    return (top->getItem());
}

string PriorityQueue::print()
{
    string output = "[";

    Node *curr = top;
    while (curr != nullptr)
    {
        output += to_string(dynamic_cast<Event *>(curr->getItem())->getTime());
        output += " ";
        curr = curr->getNext();
    }
    output += "]";
    return output;
}

int PriorityQueue::getSize()
{
    return this->size;
}
PriorityQueue::~PriorityQueue() {}