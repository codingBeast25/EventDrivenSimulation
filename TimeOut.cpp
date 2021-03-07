#include "Simulation.h"
#include "TimeOut.h"
#include "Process.h"
#include "Bursts.h"
#include "StartCpu.h"
#include "Arrival.h"
#include <iostream>
using namespace std;

TimeOut::TimeOut(int arriveT, Process *currProcess, Simulation *sim) : Event(arriveT, currProcess, sim) {}

void TimeOut::handleEvent()
{
    Simulation *sim = this->getSim();
    Process *process = this->getProcess();
    int burst = process->getCPUBurst()->getBurst();
    process->setCPUBurst(burst - sim->getTimeQ());
    sim->removeCPUTop();
    sim->addCpuBurst(process);
    if (sim->isCpuBusy())
    {
        StartCpu *newEvent = new StartCpu(this->getTime(), sim->getCpuTop(), sim);
        sim->addEvent(newEvent);
    }
}

int TimeOut::compareTo(ListItem *other)
{
    Event *otherEvent = dynamic_cast<Event *>(other);
    int boolean = 1;
    if (Arrival *temp = dynamic_cast<Arrival *>(otherEvent))
    {
        if ((this->getTime()) >= (otherEvent->getTime()))
        {
            boolean = 0;
        }
    }
    else
    {
        boolean = Event::compareTo(other);
    }
    return boolean;
}

void TimeOut::print()
{
    cout << "Time\t" << this->getTime() << ":\tProcess\t" << this->getProcess()->getId() << " times Out (needs " << this->getProcess()->getCPUBurst()->getBurst() - getSim()->getTimeQ() << " more units)." << endl;
}