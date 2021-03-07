#include "Simulation.h"
#include "StartIo.h"
#include "CompleteIo.h"
#include "Process.h"
#include "Bursts.h"
#include <iostream>
using namespace std;

StartIo::StartIo(int time, Process *currProcess, Simulation *siml) : Event(time, currProcess, siml) {}

void StartIo::handleEvent()
{
    int eventTime = getSim()->getCurrTime() + this->getProcess()->getIOBurst()->getBurst();
    CompleteIo *newEvent = new CompleteIo(eventTime, this->getProcess(), this->getSim());
    this->getSim()->addEvent(newEvent);
}

void StartIo::print()
{
    cout << "Time\t" << this->getTime() << ":\tProcess\t" << this->getProcess()->getId() << " begins I/O burst of length " << this->getProcess()->getIOBurst()->getBurst() << endl;
}
