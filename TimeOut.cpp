#include "Simulation.h"
#include "TimeOut.h"
#include "Process.h"
#include <iostream>
using namespace std;

TimeOut::TimeOut(int arriveT, Process *currProcess, Simulation *sim) : Event(arriveT, currProcess, sim) {}

void TimeOut::handleEvent()
{
}

void TimeOut::print()
{
    cout << "Time: " << this->getSim()->getCurrTime() << ": Process " << this->getProcess()->getId() << "Times Out (needs " << this->getProcess()->getCPUBurst() << " units more)." << endl;
}