#pragma once

#include <fstream>
#include <string>
class PriorityQueue;
class Queue;
class Event;
class Process;
class Bursts;
using namespace std;

class Simulation
{
private:
	ifstream inFile;
	string line;
	int timeQ;
	int currTime;
	Queue *CPUQ;
	Queue *IOQ;
	Queue *processCPUQ;
	Queue *processIOQ;
	PriorityQueue *eventList;
	int id;
	Queue *processQueue;
	// you will need to add fields
	// including: Queues for CPU and IO, and priority queues for Events
public:
	Simulation();

	// runSimulation -- start the simulation with the given filename.
	// Called by main.
	void runSimulation(char *fileName);

	void getNextProcess();

	void addEvent(Event *currEvent);
	void addProcess(Process *currProcess);
	void addProcessToEnd(Process *currProcess);
	Process *getCurrProcess();
	bool isCpuBusy();
	void addCpuBurstToEnd(int curr);
	PriorityQueue *getEventList();
	void setCurrTime(int time);
	int getCurrTime();
	int getTimeQ();

	// summary -- print a summary of all the processes, as shown in the
	// assignment.  Called by main.
	void summary();

	// you may need to add more methods

}; // class Simulation
