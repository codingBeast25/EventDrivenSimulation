#include <sstream>
#include <iostream>

#include "PriorityQueue.h"
#include "Queue.h"
#include "Event.h"
#include "Arrival.h"
#include "Simulation.h"

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
    }
}

void Simulation::getNextProcess(string line)
{
    int arrivalTime;
    int burst;
    int number;
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
            CPUQ->enqueue(dynamic_cast<ListItem *>(number));
        }
    }
}