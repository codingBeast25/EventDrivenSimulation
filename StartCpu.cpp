/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: Start cpu implementation which checks if current process needs more cpu time then the allocated time and schedule timeout event or if dosent need more than allocated time then scheudle complete cpu event.
*/
#include "Simulation.h"
#include "StartCpu.h"
#include "Process.h"
#include "CompleteCpu.h"
#include "TimeOut.h"
#include "Bursts.h"
#include <iostream>
using namespace std;

//constructor
StartCpu::StartCpu(int time, Process *currProcess, Simulation *siml) : Event(time, currProcess, siml) {}

//handles the main processing fo this event
void StartCpu::handleEvent()
{
    Simulation *sim = this->getSim();
    Process *process = this->getProcess();
    //get the current burst to process
    int burst = process->getCPUBurst()->getBurst();
    //if this burst require less time than the allocated time schedule complete cpu
    if (sim->getTimeQ() - burst >= 0)
    {
        int completeT = (sim->getCurrTime() + burst);
        CompleteCpu *newEvent = new CompleteCpu(completeT, process, sim);
        sim->addEvent(newEvent);
    }
    //else create timeout event at currTime + maximum time allowed
    else
    {

        int timeOutT = sim->getCurrTime() + sim->getTimeQ();
        TimeOut *newEvent = new TimeOut(timeOutT, process, sim);
        sim->addEvent(newEvent);
    }
}

void StartCpu::print()
{

    if (this->getProcess()->getCPUBurst()->getBurst() - getSim()->getTimeQ() <= 0)
    {
        cout << "Time\t" << this->getTime() << ":\tProcess\t" << this->getProcess()->getId() << " begins CPU burst(will complete all " << this->getProcess()->getCPUBurst()->getBurst() << " remaining units)." << endl;
    }
    else
    {
        cout << "Time\t" << this->getTime() << ":\tProcess\t" << this->getProcess()->getId() << " begins CPU burst(will time out; needs " << this->getProcess()->getCPUBurst()->getBurst() << " units total)." << endl;
    }
}
