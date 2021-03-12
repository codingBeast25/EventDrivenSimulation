/*
Name: Kabir Bhakta 		Student Number : 7900098
Purpose: Implementation of Simulation.cpp
*/
#pragma once

#include <fstream>
#include <string>
#include "ParentQueue.h"
class PriorityQueue;
class Queue;
class Event;
class Process;
using namespace std;

class Simulation
{
private:
	ifstream inFile;
	string line;
	int timeQ;				  //time quantam
	int currTime;			  //curr time of simulation
	int id;					  //current process's id
	Queue *CPUQ;			  //CPUQ for keeping track of process working in CPU
	Queue *IOQ;				  //IOQ for keeping track of process working in IO
	PriorityQueue *eventList; //Keep track of current and future events
	Queue *currProcessQueue;  //keep track of process that entered simulatiuon

public:
	Simulation(); //constructor

	// runSimulation -- start the simulation with the given filename.
	// Called by main.
	void runSimulation(char *fileName);

	void getNextProcess(); //read the next process from the file

	void addEvent(Event *currEvent); //add the event to event list

	void addProcess(Process *currProcess); //add the process to currProcessQueue

	bool isCpuBusy(); //checks if CPU is busy or not
	bool isIoBusy();  //checks if IO is busy or not

	Process *removeIOTop();	 //get CPUQ's first process
	Process *removeCPUTop(); //get IOQ's first process

	void addtoCpu(Process *processTOadd); //add the process to CPUQ
	void addtoIo(Process *processToAdd);  //add the process to IOQ

	Process *getIoTop();  //get curr Process executing on CPU
	Process *getCpuTop(); //get curr Process executing on IOQ

	void setCurrTime(int time); //set current time of the simulation
	int getCurrTime();			//get the current simualtion time
	int getTimeQ();

	// summary -- print a summary of all the processes, as shown in the
	// assignment.  Called by main.
	void summary();

}; // class Simulation
