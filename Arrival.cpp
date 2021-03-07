#include "Arrival.h"

#include "Simulation.h"
#include "StartCpu.h"
#include "Process.h"
#include <iostream>
using namespace std;
Arrival::Arrival(int arriveT, Process *currProcess, Simulation *sim) : Event(arriveT, currProcess, sim) {}

void Arrival::handleEvent()
{
    Simulation *sim = this->getSim();
    Process *process = this->getProcess();
    if (sim->isCpuBusy())
    {
        sim->addCpuBurst(process);
    }
    else
    {
        sim->addCpuBurst(process);
        StartCpu *newEvent = new StartCpu(this->getTime(), process, sim);
        sim->addEvent(newEvent);
    }
    sim->getNextProcess();
}

void Arrival::print()
{
    if (!getSim()->isCpuBusy())
    {
        cout << "Time: " << this->getTime() << ": Process " << this->getProcess()->getId() << " arrives in system: CPU is free(Process begins execution)." << endl;
    }
    else
    {
        cout << "Time: " << this->getTime() << ": Process " << this->getProcess()->getId() << " arrives in system: CPU is busy(Process will be queued)." << endl;
    }
}
