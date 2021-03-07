#include "Simulation.h"
#include "StartCpu.h"
#include "CompleteCpu.h"
#include "StartIo.h"
#include "Exit.h"
#include "Process.h"
#include <iostream>
using namespace std;

CompleteCpu::CompleteCpu(int time, Process *currProcess, Simulation *siml) : Event(time, currProcess, siml) {}

void CompleteCpu::handleEvent()
{
    Simulation *sim = this->getSim();
    Process *process = this->getProcess();
    sim->removeCPUTop();
    process->removeFromCPU();

    if (process->noMoreBursts())
    {
        Exit *newEvent = new Exit(this->getTime(), process, sim);
        sim->addEvent(newEvent);
    }
    else if (process->getIOBurst() != nullptr)
    {
        if (sim->isIoBusy())
        {
            sim->addIoBurst(process);
            //StartIo *newEvent = new StartIo(this->getTime(), this->getSim()->getIoTop(), this->getSim());
            //this->getSim()->addEvent(newEvent);
        }
        else
        {
            sim->addIoBurst(process);
            StartIo *newEvent = new StartIo(this->getTime(), process, sim);
            sim->addEvent(newEvent);
        }
    }
    if (sim->isCpuBusy())
    {

        StartCpu *newEvent = new StartCpu(this->getTime(), sim->getCpuTop(), sim);
        sim->addEvent(newEvent);
    }
}

void CompleteCpu::print()
{
    cout << "Time: " << this->getTime() << ": Process " << this->getProcess()->getId() << " completes CPU burst." << endl;
}