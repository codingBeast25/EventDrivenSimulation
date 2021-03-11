/*
* Name: Kabir Bhakta    Student Number: 7900098
* Purpose: This class drives our entire simulation data. Reads from the file but not all at once. Does all the required checks to drive the simulation. 
*/
#include <sstream>
#include <iostream>

//Include all your .h files
#include "PriorityQueue.h"
#include "Queue.h"
#include "Event.h"
#include "Arrival.h"
#include "Simulation.h"
#include "Bursts.h"
#include "Process.h"

//Constructor
Simulation::Simulation()
{
    eventList = new PriorityQueue(); //Keeps track of current and future Events
    id = 1;                          //current process's id
    CPUQ = new Queue();              //Keeps track of current and future CPU operation
    IOQ = new Queue();               //Keeps track of current and future IO operation
    currProcessQueue = new Queue();  //keeps track of all processes that entered simulation
    timeQ = 0;                       //TIme Quantam of our system
}

//Reading and handling event from file
void Simulation::runSimulation(char *fileName)
{

    inFile.open(fileName); //opening file
    if (inFile.is_open())
    {
        getline(inFile, line);
        istringstream iss(line);
        iss >> timeQ; //read the time quantam

        getNextProcess(); //read the new process from the file(entire line)

        //Runs simulation until our eventlist is empty
        while (!(eventList->isEmpty()))
        {
            Event *currEvent = dynamic_cast<Event *>(eventList->dequeue()); //dequeue from the eventlist
            currEvent->print();                                             //print event deatils
            this->setCurrTime(currEvent->getTime());                        //set the current time of simulation to currEvent time
            currEvent->handleEvent();                                       //handle the particular event
        }

        inFile.close(); //close file
    }
    else
    {
        exit(EXIT_FAILURE);
    }
}

//Reads the new process from the text file.
void Simulation::getNextProcess()
{
    if (getline(inFile, line))
    {
        Queue *processCPUQ = new Queue; //queue for Process's CPU bursts
        Queue *processIOQ = new Queue;  //queue for Process's IO bursts

        int totalBurst = 0; //sum of series of burst for a process
        int arrivalTime;    //process arrival time
        int number;
        Bursts *currBurst;
        int isItTime = 1; //the number read is it Arriavl time if 1 then yes.
        istringstream iss(line);
        while (iss >> number)
        {
            if (isItTime)
            {
                isItTime = 0;
                arrivalTime = number;
                continue;
            }
            if (number >= 0)
            {
                currBurst = new Bursts(number);
                totalBurst += number;
                processCPUQ->enqueue(currBurst); //enter into process's CPUQ
            }
            else if (number < 0)
            {
                number = -number;
                currBurst = new Bursts(number);
                totalBurst += number;
                processIOQ->enqueue(currBurst); //enter into process's IOQ
            }
        }
        //create newProcess object for the current process read from the file
        Process *newProcess = new Process(id++, arrivalTime, processCPUQ, processIOQ);

        newProcess->setTotalBurst(totalBurst); //store the total burst which will use during wait tme calculation

        //create Arrival event for the process read
        Arrival *newArrival = new Arrival(arrivalTime, newProcess, this);
        //add it to eventlist PQ
        this->addEvent(newArrival);
        //add it to currProcessQ
        this->addProcess(newProcess);
    }
}

//adds the event to event List
void Simulation::addEvent(Event *currEvent)
{
    if (currEvent != nullptr)
    {
        this->eventList->enqueue(currEvent);
    }
}

//adds the process to the processQ
void Simulation::addProcess(Process *newProcess)
{
    if (newProcess != nullptr)
    {
        this->currProcessQueue->enqueue(newProcess);
    }
}

//Checks if any process is currently executing CPU operation
//return true if it is or false if it is not
bool Simulation::isCpuBusy()
{
    if (CPUQ->isEmpty())
    {
        return false;
    }
    else
    {
        return true;
    }
}

//Checks if any process is currently executing IO operation
//return true if it is or false if it is not
bool Simulation::isIoBusy()
{
    if (IOQ->isEmpty())
    {
        return false;
    }
    else
    {
        return true;
    }
}

//adds the process to CPUQ to wait for its turn to execute its cpu operation
void Simulation::addtoCpu(Process *processToAdd)
{
    this->CPUQ->enqueue(processToAdd);
}

//adds the process to IOQ to wait for its turn to execute its io operation
void Simulation ::addtoIo(Process *processToAdd)
{
    this->IOQ->enqueue(processToAdd);
}

//returns the current process executing on CPU
Process *Simulation::getCpuTop()
{
    return dynamic_cast<Process *>(this->CPUQ->getFront());
}

//returns the current process executing on IO
Process *Simulation::getIoTop()
{
    return dynamic_cast<Process *>(this->IOQ->getFront());
}

//removes the current process from CPUQ
Process *Simulation::removeCPUTop()
{
    return dynamic_cast<Process *>(this->CPUQ->dequeue());
}

//removes the current process from IOQ
Process *Simulation::removeIOTop()
{
    return dynamic_cast<Process *>(this->IOQ->dequeue());
}

//Sets the current simulation time
void Simulation::setCurrTime(int time)
{
    currTime = time;
}

//return the time quantam read from the file
int Simulation::getTimeQ()
{
    return timeQ;
}

//return the current time of the simulation
int Simulation::getCurrTime()
{
    return currTime;
}

//prints the summary of the simulation
void Simulation::summary()
{
    cout << "Process\tArrival\tExit\tWait" << endl;
    cout << "      #\t   Time\tTime\tTime" << endl;
    cout << "------------------------------------" << endl;
    while (!currProcessQueue->isEmpty())
    {

        Process *currProcess = dynamic_cast<Process *>(currProcessQueue->dequeue());
        currProcess->print();
    }
}