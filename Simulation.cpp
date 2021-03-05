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
    processQueue = new Queue();
    timeQ = 0;
    id = 0;
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
            Event *currEvent = dynamic_cast<Event *>(getEventList()->dequeue());
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
            cout << "current number:" << number << endl;
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
        this->processQueue->enqueue(newProcess);
    }
    id++;
}

void Simulation::addProcessToEnd(Process *currProcess)
{
    this->processQueue->enqueue(processQueue->dequeue());
}

Process *Simulation::getCurrProcess()
{
    return dynamic_cast<Process *>(this->processQueue->getFront());
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

void Simulation::addCpuBurstToEnd(int curr)
{
    Bursts *curCpuBurst = new Bursts(curr);
    this->CPUQ->enqueue(curCpuBurst);
}

PriorityQueue *Simulation::getEventList()
{
    return this->eventList;
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