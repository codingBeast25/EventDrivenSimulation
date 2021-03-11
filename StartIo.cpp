/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: Start Io implementation which schedules complete io event and addd it to the eventlist
*/
#include "Simulation.h"
#include "StartIo.h"
#include "CompleteIo.h"
#include "Process.h"
#include "Bursts.h"
#include <iostream>
using namespace std;

//constructor
StartIo::StartIo(int time, Process *currProcess, Simulation *siml) : Event(time, currProcess, siml) {}

void StartIo::handleEvent()
{
    //set the completeIo time to currTIme+curr IO burst length
    int eventTime = getSim()->getCurrTime() + this->getProcess()->getIOBurst()->getBurst();
    //schedule a new CompleteIo event
    CompleteIo *newEvent = new CompleteIo(eventTime, this->getProcess(), this->getSim());
    this->getSim()->addEvent(newEvent);
}

void StartIo::print()
{
    cout << "Time\t" << this->getTime() << ":\tProcess\t" << this->getProcess()->getId() << " begins I/O burst of length " << this->getProcess()->getIOBurst()->getBurst() << endl;
}
