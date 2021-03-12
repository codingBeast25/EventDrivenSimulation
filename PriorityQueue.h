/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: priority queue defination.
*/

#pragma once
#include "ParentQueue.h"
class Node;
class ListItem;
class Event;

using namespace std;

class PriorityQueue: public ParentQueue
{

public:
    PriorityQueue(); //constructor

    //insert event accorind to priority
    void enqueue(ListItem *item);

    //default destructor
    ~PriorityQueue();
};