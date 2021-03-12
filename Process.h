/*
Name: Kabir Bhakta 		Student Number : 7900098
Purpose: Implementation of Process.cpp
*/
#pragma once
#include "ParentQueue.h"
#include "ListItem.h"
class Queue;
class Bursts;

class Process : public ListItem
{
private:
    int id;          //process id
    int arrivalTime; //arrival time of the process
    int exitTime;    //exit time of process
    int waitTime;    //wait time of process
    Queue *cpuQ;     //queue for cpu bursts of a process
    Queue *ioQ;      //queue for io bursts
    int totalBurst;  //total burst amount

public:
    //constructor
    Process(int id, int arrivalTime, Queue *cpuQ, Queue *ioQ);
    //set the sum of all bursts
    void setTotalBurst(int total);
    //get the summ of all bursts
    int getTotalBurst();
    //get process id
    int getId();
    //get the current cpu burst
    Bursts *getCPUBurst();
    //get the current IO burst
    Bursts *getIOBurst();
    //check if any more burst are there or not
    bool noMoreBursts();
    //change the current cpu burst
    void setCPUBurst(int newBurst);
    //remove from top of cpu burst q
    Bursts *removeFromIO();
    //remove from top of io burst q
    Bursts *removeFromCPU();

    int getArrTime();
    int getExitTime();
    int getWaitTime();

    void setExitTime(int exitTime);
    void setWaitTime();

    //compare to method of the process
    int compareTo(ListItem *other);
    void print();

    ~Process();
};