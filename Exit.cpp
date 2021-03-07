#include "Simulation.h"
#include "Exit.h"
#include "Process.h"
#include <iostream>
using namespace std;

Exit::Exit(int time, Process *currProcess, Simulation *siml) : Event(time, currProcess, siml) {}

void Exit::handleEvent()
{
    Simulation *sim = sim;
    Process *process = process;
    sim->addToTempQueue(process);

    process->setExitTime(this->getTime());
    process->setWaitTime();
}

void Exit::print()
{
    cout << "Time " << this->getTime() << ":Process " << this->getProcess()->getId() << " completes all its CPU and I/O burst. It exits Simulation." << endl;
}