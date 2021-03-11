/*
*Name : Kabir Bhakta    Student Number: 7900098
*Purpose : CompleteIo implementation which checks if there is more burst to process in the series or not. IF there is then schedule the next cpu start event or schedule the next Io start fromIOQ
*/
#include "Simulation.h"
#include "StartIo.h"
#include "StartCpu.h"
#include "Exit.h"
#include "CompleteIo.h"
#include "Process.h"
#include "Bursts.h"
#include <iostream>
using namespace std;

//constructor
CompleteIo::CompleteIo(int time, Process *currProcess, Simulation *siml) : Event(time, currProcess, siml) {}

//Main processing is done here
void CompleteIo::handleEvent()
{
    Simulation *sim = this->getSim();
    Process *process = this->getProcess();
    //remove from the IOQ
    sim->removeIOTop();
    //remove burst from process
    process->removeFromIO();

    //check if more burst to process in the series
    if (process->noMoreBursts())
    {
        //if not schedule exit event
        Exit *newEvent = new Exit(this->getTime(), process, sim);
        sim->addEvent(newEvent);
    }
    else if (process->getCPUBurst() != nullptr)
    {
        //if there is next burst then check if cpu is currently busy or not if it is then schedule start cpu on top of Queue process
        if (sim->isCpuBusy())
        {
            sim->addtoCpu(process);
        }
        else
        {
            //if not then start cpu on current process
            sim->addtoCpu(process);
            StartCpu *newEvent = new StartCpu(this->getTime(), process, sim);
            sim->addEvent(newEvent);
        }
    }
    if (sim->isIoBusy())
    {
        //start Io on first in queue of process in IOQ
        StartIo *newEvent = new StartIo(this->getTime(), sim->getIoTop(), sim);
        sim->addEvent(newEvent);
    }
}

void CompleteIo::print()
{
    cout << "Time\t" << this->getTime() << ":\tProcess\t" << this->getProcess()->getId() << " completes I/O burst of length " << this->getProcess()->getIOBurst()->getBurst() << endl;
}
