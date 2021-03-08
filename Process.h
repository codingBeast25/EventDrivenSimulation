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
    int totalBurst;

public:
    Process(int id, int arrivalTime, Queue *cpuQ, Queue *ioQ);
    void setTotalBurst(int total);
    int getTotalBurst();
    int getId();
    Bursts *getCPUBurst();
    Bursts *getIOBurst();
    bool noMoreBursts();
    void setCPUBurst(int newBurst);
    Bursts *removeFromIO();
    Bursts *removeFromCPU();
    int getArrTime();
    int getExitTime();
    int getWaitTime();
    void setExitTime(int exitTime);
    void setWaitTime();
    int compareTo(ListItem *other);
    void print();
    ~Process();
};