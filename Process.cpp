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

bool Process::noMoreBursts()
{
    if (this->getIOBurst() == nullptr && this->getCPUBurst() == nullptr)
    {
        return true;
    }
    else
        return false;
}

Bursts *Process::getCPUBurst()
{
    Bursts *retBurst = dynamic_cast<Bursts *>(cpuQ->getFront());
    if (retBurst != nullptr)
    {
        return retBurst;
    }
    else
    {
        return nullptr;
    }
}

Bursts *Process::getIOBurst()
{
    Bursts *retBurst = dynamic_cast<Bursts *>(ioQ->getFront());
    if (retBurst != nullptr)
    {
        return retBurst;
    }
    else
    {
        return nullptr;
    }
}

void Process::setCPUBurst(int newBurst)
{
    Bursts *newBursts = dynamic_cast<Bursts *>(cpuQ->getFront());
    newBursts->setBurst(newBurst);
    cpuQ->enqueue(cpuQ->dequeue());
}

void Process::removeFromCPU()
{
    this->cpuQ->dequeue();
}

void Process::removeFromIO()
{
    this->ioQ->dequeue();
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
    waitTime = exitTime - arrivalTime;
}

int Process::compareTo(ListItem *other)
{
    int boolean = 0;
    Process *otherProcess = dynamic_cast<Process *>(other);
    if (this->getId() > otherProcess->getId())
    {
        boolean = 1;
    }
    else if (this->getId() < otherProcess->getId())
    {
        boolean = -1;
    }
    return boolean;
}