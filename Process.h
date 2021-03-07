#pragma once

#include "ListItem.h"
#include "Queue.h"
class Bursts;

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
    Bursts *getCPUBurst();
    Bursts *getIOBurst();
    bool noMoreBursts();
    void setCPUBurst(int newBurst);
    void removeFromIO();
    void removeFromCPU();
    int getArrTime();
    int getExitTime();
    int getWaitTime();
    void setExitTime(int exitTime);
    void setWaitTime();
    int compareTo(ListItem *other);
    void print();
    ~Process();
};