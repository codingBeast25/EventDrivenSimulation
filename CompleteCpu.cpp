/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: Complete cpu implementation which checks if current CPUQ is busy or not if it is then wait in the queue if not then check for if more burst in the current process or not and schedule first cpu burst in the queue
*/
#include "Simulation.h"
#include "StartCpu.h"
#include "CompleteCpu.h"
#include "StartIo.h"
#include "Exit.h"
#include "Process.h"
#include <iostream>
using namespace std;

CompleteCpu::CompleteCpu(int time, Process *currProcess, Simulation *siml) : Event(time, currProcess, siml) {}

//All the processing happens here read the description
void CompleteCpu::handleEvent()
{
    Simulation *sim = this->getSim();
    Process *process = this->getProcess();
    //remove from CPUQ current process
    sim->removeCPUTop();
    //remove the current bursts from the series of burst of a process
    process->removeFromCPU();

    //if no more burst to process in this process then call exit event
    if (process->noMoreBursts())
    {
        Exit *newEvent = new Exit(this->getTime(), process, sim);
        sim->addEvent(newEvent);
    }
    //if there is IO burst to process next then check if IO is busy or not and proceed
    else if (process->getIOBurst() != nullptr)
    {
        if (sim->isIoBusy())
        {
            //io is busy so add it to the queue and wait for the turn
            sim->addtoIo(process);
        }
        else
        {
            //io is free then add it to the queue schedule startIO and add it to event list
            sim->addtoIo(process);
            StartIo *newEvent = new StartIo(this->getTime(), process, sim);
            sim->addEvent(newEvent);
        }
    }
    if (sim->isCpuBusy())
    {
        //if cpu is busy then schedule the startcpu process on the first process in the CPUQ
        StartCpu *newEvent = new StartCpu(this->getTime(), sim->getCpuTop(), sim);
        sim->addEvent(newEvent);
    }
}

void CompleteCpu::print()
{
    cout << "Time\t" << this->getTime() << ":\tProcess\t" << this->getProcess()->getId() << " completes CPU burst." << endl;
}