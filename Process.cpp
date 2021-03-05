#include "Process.h"
#include "Bursts.h"

Process::Process(int id, int arrivalTime, Queue *cpuQ, Queue *ioQ)
{
    this->id = id;
    this->arrivalTime = arrivalTime;
    this->cpuQ = cpuQ;
    this->ioQ = ioQ;
    this->waitTime = 0;
    this->exitTime = 0;
}

int Process::getId()
{
    return id;
}

Queue *Process::getQueue(int which)
{
    if (which == 0)
    {
        return cpuQ;
    }
    else
    {
        return ioQ;
    }
}

int Process::getCPUBurst()
{
    Bursts *retBurst = dynamic_cast<Bursts *>(cpuQ->getFront());
    if (retBurst != nullptr)
    {
        return retBurst->getBurst();
    }
    else
    {
        return 0;
    }
}

int Process::compareTo(ListItem *other)
{
    return -1;
}