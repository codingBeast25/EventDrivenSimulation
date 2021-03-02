#include <sstream>
#include <iostream>

#include "PriorityQueue.h"
#include "Queue.h"
#include "Event.h"
#include "Arrival.h"
#include "Simulation.h"
#include "Bursts.h"

Simulation::Simulation()
{
}

void Simulation::runSimulation(char *fileName)
{

    inFile.open(fileName);
    if (inFile.is_open())
    {
        getline(inFile, line);
        timeQ = stoi(line);
        getline(inFile, line);
        getNextProcess(line);
        while (!(eventList->isEmpty()))
        {
            Event *currEvent = dynamic_cast<Event *>(getEventList()->dequeue());
            this->setCurrTime(currEvent->getTime());
            currEvent->handleEvent();
        }
    }
}

void Simulation::getNextProcess(string line)
{
    int arrivalTime;
    int number;
    Bursts *currBurst;
    int isItArrival = 1;
    istringstream iss(line);
    while (iss >> number)
    {
        if (isItArrival)
        {
            isItArrival = 0;
            arrivalTime = number;
            continue;
        }
        if (number >= 0)
        {
            currBurst = new Bursts(number);
            CPUQ->enqueue(currBurst);
        }
        else if (number < 0)
        {
            currBurst = new Bursts(0 - number);
            IOQ->enqueue(currBurst);
        }
    }

    Arrival *newArrival = new Arrival(arrivalTime, CPUQ, IOQ);
    this->addEvent(newArrival);
}

void Simulation::addEvent(Event *currEvent)
{
    if (currEvent != nullptr)
    {
        this->eventList->enqueue(currEvent);
    }
}

PriorityQueue *Simulation::getEventList()
{
    return this->eventList;
}

void Simulation::setCurrTime(int time)
{
    currTime = time;
}