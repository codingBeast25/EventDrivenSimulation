/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: Queue defination
*/
#pragma once
#include "ParentQueue.h"
class Node;
class ListItem;

class Queue: public ParentQueue
{
public:
	Queue();
	void enqueue(ListItem *item);
}; // class Queue
