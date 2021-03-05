#pragma once

#include "ListItem.h"
#include "Queue.h"

class Process : public ListItem
{
private:
    int id;
    int arrivalTime;
    int exitTime;
    int waitTime;
    Queue *cpuQ;
    Queue *ioQ;

public:
    Process(int id, int arrivalTime, Queue *cpuQ, Queue *ioQ);
    int getId();
    Queue *getQueue(int which);
    int getCPUBurst();
    void setCPUBurst(int newBurst);
    int getArrTime();
    int getExitTime();
    int getWaitTime();
    int compareTo(ListItem *other);
    void print();
    ~Process();
};