/*
*Name : Kabir Bhakta    Student Number: 7900098
*Purpose : Exit implementation which gathers all the statistics of the process and store it in to be printed at the end of the execution of the entire simulation
*/
#include "Simulation.h"
#include "Exit.h"
#include "Process.h"
#include <iostream>
using namespace std;

//constructor
Exit::Exit(int time, Process *currProcess, Simulation *siml) : Event(time, currProcess, siml) {}

//Set the exit time of the process and also set the wait time of the process
void Exit::handleEvent()
{
    Simulation *sim = this->getSim();
    Process *process = this->getProcess();
    process->setExitTime(this->getTime());
    process->setWaitTime();
}

void Exit::print()
{
    cout << "Time\t" << this->getTime() << ":\tProcess\t" << this->getProcess()->getId() << " completes all its CPU and I/O burst. It exits Simulation." << endl;
}