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
	Queue *currProcessQueue;
	Queue *totalProcessQueue;
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
	void addProcessToEnd();
	Process *getCurrProcess();
	bool isCpuBusy();
	bool isIoBusy();
	Process *removeIOTop();
	Process *removeCPUTop();
	void addCpuBurst(Process *processTOadd);
	void addIoBurst(Process *processToAdd);
	void addCpuBurstToEnd();
	void setCurrCpuBurst(int newB);
	Process *getIoTop();
	Process *getCpuTop();
	void addToTempQueue(Process *currProcess);

	void setCurrTime(int time);
	int getCurrTime();
	int getTimeQ();

	// summary -- print a summary of all the processes, as shown in the
	// assignment.  Called by main.
	void summary();

	// you may need to add more methods

}; // class Simulation
