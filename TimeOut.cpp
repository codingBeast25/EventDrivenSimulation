/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: TimeOut Event implementation. When a process times out in system.
*/
#include "Simulation.h"
#include "TimeOut.h"
#include "Process.h"
#include "Bursts.h"
#include "StartCpu.h"
#include "Arrival.h"
#include <iostream>
using namespace std;

//constructor
TimeOut::TimeOut(int arriveT, Process *currProcess, Simulation *sim) : Event(arriveT, currProcess, sim) {}

//Handle event will do the main processing  and create another event accordingly
void TimeOut::handleEvent()
{
    Simulation *sim = this->getSim();
    Process *process = this->getProcess();
    //get the current burst
    int burst = process->getCPUBurst()->getBurst();
    //set the new burst
    process->setCPUBurst(burst - sim->getTimeQ());
    //remove the process from cpu and add it to end.
    sim->removeCPUTop();
    sim->addtoCpu(process);
    //check if cpu is busy or not
    if (sim->isCpuBusy())
    {
        //start new cpu event and add it to the event list
        StartCpu *newEvent = new StartCpu(this->getTime(), sim->getCpuTop(), sim);
        sim->addEvent(newEvent);
    }
}

void TimeOut::print()
{
    cout << "Time\t" << this->getTime() << ":\tProcess\t" << this->getProcess()->getId() << " times Out (needs " << this->getProcess()->getCPUBurst()->getBurst() - getSim()->getTimeQ() << " more units)." << endl;
}