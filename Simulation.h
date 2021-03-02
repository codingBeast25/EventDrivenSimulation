#pragma once

#include <fstream>
#include <string>
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
	int timeQ;
	int currTime;
	Queue *CPUQ;
	Queue *IOQ;
	PriorityQueue *eventList;
	// you will need to add fields
	// including: Queues for CPU and IO, and priority queues for Events
public:
	Simulation();

	// runSimulation -- start the simulation with the given filename.
	// Called by main.
	void runSimulation(char *fileName);

	void getNextProcess(string line);

	void addEvent(Event *currEvent);
	PriorityQueue *getEventList();
	void setCurrTime(int time);

	// summary -- print a summary of all the processes, as shown in the
	// assignment.  Called by main.
	void summary();

	// you may need to add more methods

}; // class Simulation
