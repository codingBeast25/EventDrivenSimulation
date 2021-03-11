/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: Arrvial Event implementation. When a process arrives in system.
*/
#include "Arrival.h"
#include "Simulation.h"
#include "StartCpu.h"
#include "Process.h"
#include "TimeOut.h"
#include <iostream>
using namespace std;

//constructor
Arrival::Arrival(int arriveT, Process *currProcess, Simulation *sim) : Event(arriveT, currProcess, sim) {}

//Handle event will do the main processing  and create another event accordingly
void Arrival::handleEvent()
{
    Simulation *sim = this->getSim();
    Process *process = this->getProcess();
    if (sim->isCpuBusy()) //check if cpu is currently proccessing anything or not
    {
        sim->addtoCpu(process); //if it is proccessing then add to end of the queue
    }
    else
    {
        sim->addtoCpu(process); //if cpu is free then add to queue and start cpu event should be added to the event list
        StartCpu *newEvent = new StartCpu(this->getTime(), process, sim);
        sim->addEvent(newEvent);
    }
    sim->getNextProcess(); //read new arriavl from the file
}

void Arrival::print()
{
    if (!getSim()->isCpuBusy())
    {
        cout << "Time\t" << this->getTime() << ":\tProcess\t" << this->getProcess()->getId() << " arrives in system: CPU is free(Process begins execution)." << endl;
    }
    else
    {
        cout << "Time\t" << this->getTime() << ":\tProcess\t" << this->getProcess()->getId() << " arrives in system: CPU is busy(Process will be queued)." << endl;
    }
}
