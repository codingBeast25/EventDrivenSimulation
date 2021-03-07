#include "Simulation.h"
#include "StartIo.h"
#include "StartCpu.h"
#include "Exit.h"
#include "CompleteIo.h"
#include "Process.h"
#include "Bursts.h"
#include <iostream>
using namespace std;

CompleteIo::CompleteIo(int time, Process *currProcess, Simulation *siml) : Event(time, currProcess, siml) {}

void CompleteIo::handleEvent()
{
    Simulation *sim = sim;
    Process *process = process;
    sim->removeIOTop();
    process->removeFromIO();

    if (process->noMoreBursts())
    {
        Exit *newEvent = new Exit(this->getTime(), process, sim);
        sim->addEvent(newEvent);
    }
    else if (process->getCPUBurst() != nullptr)
    {
        if (sim->isCpuBusy())
        {
            sim->addCpuBurst(process);
            //StartCpu *newEvent = new StartCpu(this->getTime(), sim->getCpuTop(), sim);
            //sim->addEvent(newEvent);
        }
        else
        {
            sim->addCpuBurst(process);
            StartCpu *newEvent = new StartCpu(this->getTime(), process, sim);
            sim->addEvent(newEvent);
        }
    }
    if (sim->isIoBusy())
    {
        StartIo *newEvent = new StartIo(this->getTime(), sim->getIoTop(), sim);
        sim->addEvent(newEvent);
    }
}

void CompleteIo::print()
{
    cout << "Time " << this->getTime() << ": Process " << this->getProcess()->getId() << " completes I/O burst of length " << this->getProcess()->getIOBurst()->getBurst() << endl;
}
