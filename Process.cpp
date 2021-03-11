/*
* Name: Kabir Bhakta    Student Number: 7900098
* Purpose: This class has each and every detail of the process. 
*/
#include "Process.h"
#include "Bursts.h"
#include "Queue.h"
#include <iostream>

using namespace std;
//constructor
Process::Process(int id, int arrivalTime, Queue *cpuQ, Queue *ioQ)
{
    this->id = id;
    this->arrivalTime = arrivalTime;
    this->cpuQ = cpuQ;
    this->ioQ = ioQ;
    this->waitTime = 0;
    this->exitTime = 0;
}

//sum of all the bursts
int Process::getTotalBurst()
{
    return totalBurst;
}

//sets the sum of all the bursts
void Process::setTotalBurst(int newTotal)
{
    totalBurst = newTotal;
}
//returns the id of the process
int Process::getId()
{
    return id;
}

//checks if the process has more bursts to process or not
bool Process::noMoreBursts()
{
    if (this->getIOBurst() == nullptr && this->getCPUBurst() == nullptr)
    {
        return true;
    }
    else
        return false;
}

//returns the top burst from the cpu bursts
Bursts *Process::getCPUBurst()
{
    return dynamic_cast<Bursts *>(cpuQ->getFront());
}

//returns the top burst from the io bursts
Bursts *Process::getIOBurst()
{
    return dynamic_cast<Bursts *>(ioQ->getFront());
}

//sets the current cpu burst a new value
void Process::setCPUBurst(int newBurst)
{
    dynamic_cast<Bursts *>(cpuQ->getFront())->setBurst(newBurst);
}

//removes the top burst of the CPu burst
Bursts *Process::removeFromCPU()
{
    return dynamic_cast<Bursts *>(this->cpuQ->dequeue());
}

//removes the top burst of the io burst
Bursts *Process::removeFromIO()
{
    return dynamic_cast<Bursts *>(this->ioQ->dequeue());
}

int Process::getArrTime()
{
    return arrivalTime;
}

int Process::getExitTime()
{
    return exitTime;
}

int Process::getWaitTime()
{
    return waitTime;
}

void Process::setExitTime(int exit)
{
    exitTime = exit;
}

void Process::setWaitTime()
{
    waitTime = exitTime - arrivalTime - getTotalBurst();
}

//compares with other process based on the id number
int Process::compareTo(ListItem *other)
{
    int boolean = 0;
    Process *otherProcess = dynamic_cast<Process *>(other);
    if (this->getId() < otherProcess->getId())
    {
        boolean = 1;
    }
    return boolean;
}

void Process::print()
{
    cout << "" << this->getId() << "\t" << this->getArrTime() << "\t" << this->getExitTime() << "\t" << this->getWaitTime() << endl;
}