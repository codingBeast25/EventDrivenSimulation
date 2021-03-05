#include "Simulation.h"
#include "StartCpu.h"
#include "Process.h"
#include "CompleteCpu.h"
#include "TimeOut.h"
#include <iostream>
using namespace std;

StartCpu::StartCpu(int time, Process *currProcess, Simulation *siml) : Event(time, currProcess, siml) {}

void StartCpu::handleEvent()
{

    if (((getProcess()->getCPUBurst()) - (getSim()->getTimeQ())) <= 0)
    {
        int completeT = (getSim()->getCurrTime() + this->getProcess()->getCPUBurst());
        CompleteCpu *cpuComplete = new CompleteCpu(completeT, this->getProcess(), this->getSim());
        this->getSim()->addEvent(cpuComplete);
    }
    else
    {
        this->getProcess()->setCPUBurst(this->getProcess()->getCPUBurst() - getSim()->getTimeQ());
        TimeOut *cpuTimeout = new TimeOut(getSim()->getTimeQ() + this->getTime(), this->getProcess(), this->getSim());
        this->getSim()->addEvent(cpuTimeout);
    }
}

void StartCpu::print()
{
    if (((getProcess()->getCPUBurst()) - (getSim()->getTimeQ())) <= 0)
    {
        cout << "Time: " << this->getSim()->getCurrTime() << ": Process " << this->getProcess()->getId() << " begins CPU burst(will complete all) " << this->getProcess()->getCPUBurst() << " remaining units)." << endl;
    }
    else
    {
        cout << "Time: " << this->getSim()->getCurrTime() << ": Process " << this->getProcess()->getId() << " begins CPU burst(will time out; needs) " << this->getProcess()->getCPUBurst() << " units total)." << endl;
    }
}
