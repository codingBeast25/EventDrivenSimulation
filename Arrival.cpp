#include "Arrival.h"

#include "Simulation.h"
#include "StartCpu.h"
#include "Process.h"
#include <iostream>
using namespace std;
Arrival::Arrival(int arriveT, Process *currProcess, Simulation *sim) : Event(arriveT, currProcess, sim) {}

void Arrival::handleEvent()
{

    if (!getSim()->isCpuBusy())
    {
        StartCpu *cpuStart = new StartCpu(Event::getTime(), this->getProcess(), this->getSim());

        getSim()->addCpuBurstToEnd(this->getProcess()->getCPUBurst());
        getSim()->addEvent(cpuStart);
    }
    else
    {
        getSim()->addProcessToEnd(this->getProcess());
        getSim()->addCpuBurstToEnd(this->getProcess()->getCPUBurst());
    }
    this->getSim()->getNextProcess();
}

void Arrival::print()
{
    cout << 123 << endl;
}
