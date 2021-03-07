#include <sstream>
#include <iostream>

#include "PriorityQueue.h"
#include "Queue.h"
#include "Event.h"
#include "Arrival.h"
#include "Simulation.h"
#include "Bursts.h"
#include "Process.h"

Simulation::Simulation()
{
    eventList = new PriorityQueue();
    CPUQ = new Queue();
    IOQ = new Queue();
    processCPUQ = new Queue();
    processIOQ = new Queue();
    currProcessQueue = new Queue();
    totalProcessQueue = new Queue();
    timeQ = 0;
    id = 1;
}

void Simulation::runSimulation(char *fileName)
{

    inFile.open(fileName);
    if (inFile.is_open())
    {
        getline(inFile, line);
        istringstream iss(line);
        iss >> timeQ;

        getNextProcess();

        while (!(eventList->isEmpty()))
        {
            Event *currEvent = dynamic_cast<Event *>(eventList->dequeue());
            currEvent->print();
            this->setCurrTime(currEvent->getTime());
            currEvent->handleEvent();
        }
    }

    inFile.close();
}

void Simulation::getNextProcess()
{

    if (getline(inFile, line))
    {
        int arrivalTime;
        int number;
        Bursts *currBurst;
        int isItTime = 1;
        istringstream iss(line);
        while (iss >> number)
        {
            if (isItTime)
            {
                isItTime = 0;
                arrivalTime = number;
                continue;
            }
            if (number >= 0)
            {
                currBurst = new Bursts(number);

                processCPUQ->enqueue(currBurst);
            }
            else if (number < 0)
            {
                currBurst = new Bursts(0 - number);
                processIOQ->enqueue(currBurst);
            }
        }
        Process *newProcess = new Process(id++, arrivalTime, processCPUQ, processIOQ);
        Arrival *newArrival = new Arrival(arrivalTime, newProcess, this);
        this->addEvent(newArrival);
        this->addProcess(newProcess);
    }
}

void Simulation::addEvent(Event *currEvent)
{
    if (currEvent != nullptr)
    {
        this->eventList->enqueue(currEvent);
    }
}

void Simulation::addProcess(Process *newProcess)
{
    if (newProcess != nullptr)
    {
        this->currProcessQueue->enqueue(newProcess);
    }
}

Process *Simulation::getCurrProcess()
{
    return dynamic_cast<Process *>(this->currProcessQueue->getFront());
}

bool Simulation::isCpuBusy()
{
    if (CPUQ->getFront() == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Simulation::isIoBusy()
{
    if (IOQ->getFront() == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Simulation::addCpuBurst(Process *processToAdd)
{
    this->CPUQ->enqueue(processToAdd);
}

void Simulation ::addIoBurst(Process *processToAdd)
{
    this->IOQ->enqueue(processToAdd);
}

void Simulation::addCpuBurstToEnd()
{
    this->CPUQ->enqueue(CPUQ->dequeue());
}

void Simulation::setCurrCpuBurst(int newVal)
{
    dynamic_cast<Process *>(this->CPUQ->getFront())->setCPUBurst(newVal);
}

Process *Simulation::getCpuTop()
{
    return dynamic_cast<Process *>(this->CPUQ->getFront());
}

Process *Simulation::getIoTop()
{
    return dynamic_cast<Process *>(this->IOQ->getFront());
}

Process *Simulation::removeCPUTop()
{
    return dynamic_cast<Process *>(this->CPUQ->dequeue());
}

Process *Simulation::removeIOTop()
{
    return dynamic_cast<Process *>(this->IOQ->dequeue());
}

void Simulation::addToTempQueue(Process *currProcess)
{
    this->totalProcessQueue->enqueue(currProcess);
}

void Simulation::setCurrTime(int time)
{
    currTime = time;
}

int Simulation::getTimeQ()
{
    return timeQ;
}

int Simulation::getCurrTime()
{
    return currTime;
}

void Simulation::summary()
{
    while (!totalProcessQueue->isEmpty())
    {
        Process *currProcess = dynamic_cast<Process *>(totalProcessQueue->dequeue());
        cout << currProcess->getId() << "\t" << currProcess->getArrTime() << "\t" << currProcess->getExitTime() << "\t" << currProcess->getWaitTime() << endl;
    }
}