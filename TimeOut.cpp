#include "Simulation.h"
#include "TimeOut.h"
#include "Process.h"
#include "Bursts.h"
#include "StartCpu.h"
#include <iostream>
using namespace std;

TimeOut::TimeOut(int arriveT, Process *currProcess, Simulation *sim) : Event(arriveT, currProcess, sim) {}

void TimeOut::handleEvent()
{
    Simulation *sim = this->getSim();
    Process *process = this->getProcess();
    sim->addCpuBurst(process);
    if (this->getSim()->isCpuBusy())
    {
        StartCpu *newEvent = new StartCpu(this->getTime(), sim->getCpuTop(), sim);
        sim->addEvent(newEvent);
    }
}

void TimeOut::print()
{
    cout << "Time: " << this->getTime() << ": Process " << this->getProcess()->getId() << " times Out (needs " << this->getProcess()->getCPUBurst()->getBurst() << " more units)." << endl;
}