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

int Process::getTotalBurst()
{
    return totalBurst;
}

void Process::setTotalBurst(int newTotal)
{
    totalBurst = newTotal;
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
    return dynamic_cast<Bursts *>(cpuQ->getFront());
}

Bursts *Process::getIOBurst()
{
    return dynamic_cast<Bursts *>(ioQ->getFront());
}

void Process::setCPUBurst(int newBurst)
{
    dynamic_cast<Bursts *>(cpuQ->getFront())->setBurst(newBurst);
    cpuQ->enqueue(cpuQ->dequeue());
}

Bursts *Process::removeFromCPU()
{
    return dynamic_cast<Bursts *>(this->cpuQ->dequeue());
}

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