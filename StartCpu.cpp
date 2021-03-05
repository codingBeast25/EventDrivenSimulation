#include "Simulation.h"
#include "StartCpu.h"
#include "Process.h"
#include <iostream>
using namespace std;

StartCpu::StartCpu(int time, Process *currProcess, Simulation *siml) : Event(time, currProcess, siml) {}

void StartCpu::handleEvent()
{
    cout << "CUrrent Cpu Burst: " << getProcess()->getCPUBurst() << "TImeQ: " << getSim()->getTimeQ() << "Current Time: " << getSim()->getCurrTime() << endl;
    if (((getProcess()->getCPUBurst()) - (getSim()->getTimeQ())) <= 0)
    {
        getSim()->setCurrTime(getSim()->getCurrTime() + Event::getTime());
        cout << "CPU COMPLETE WILL OCCUR" << endl;
        /*CompleteCpu *cpuComplete = new CompleteCpu(getSim()->getCurrTime(), this->getProcess(), this->getSim());
        this->getSim()->addEvent(cpuComplete);*/
    }
    else
    {
        cout << "CPU TIMEOUT WILL OCCUR" << endl;
        //getSim()->setCurrTime(this->getTime());
        /*Timeout *cpuTimeout = new Timeout(getSim()->getCurrTime(), this->getProcess(), this->getSim());
        this->getSim()->addEvent(cpuTimeout);*/
    }
}

void StartCpu::print()
{
    cout << 123 << endl;
}
