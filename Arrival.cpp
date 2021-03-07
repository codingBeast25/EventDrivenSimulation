#include "Arrival.h"
#include "Simulation.h"
#include "StartCpu.h"
#include "Process.h"
#include "TimeOut.h"
#include <iostream>
using namespace std;
Arrival::Arrival(int arriveT, Process *currProcess, Simulation *sim) : Event(arriveT, currProcess, sim) {}

template <typename Base, typename T>
inline bool instanceof (const T *)
{
    return is_base_of<Base, T>::value;
}

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

int Arrival::compareTo(ListItem *other)
{
    Event *otherEvent = dynamic_cast<Event *>(other);
    int boolean = 0;
    if (TimeOut *temp = dynamic_cast<TimeOut *>(otherEvent))
    {
        if ((this->getTime()) <= (otherEvent->getTime()))
        {
            boolean = 1;
        }
    }
    else
    {
        boolean = Event::compareTo(other);
    }
    return boolean;
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
