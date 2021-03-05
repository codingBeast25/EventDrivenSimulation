#include "Simulation.h"
#include "CompleteCpu.h"
#include "Process.h"
#include <iostream>
using namespace std;

CompleteCpu::CompleteCpu(int time, Process *currProcess, Simulation *siml) : Event(time, currProcess, siml) {}

void CompleteCpu::handleEvent()
{
}

void CompleteCpu::print()
{
    cout << "Time: " << this->getSim()->getCurrTime() << ": Process " << this->getProcess()->getId() << " completes CPU burst." << endl;
}