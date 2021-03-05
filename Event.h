#pragma once
#include "ListItem.h"
class Process;
class Simulation;

class Event : public ListItem
{
private:
	int eventTime;
	Process *process;

protected:
	Simulation *sim;
	Simulation *getSim();
	Process *getProcess();

public:
	// constructor, with pointer to the process that is being handled, and the simulation.
	Event(int theTime, Process *theProcess, Simulation *sim);
	Event();

	// pure virtual method - to handle the current event when it is removed from the queue.
	virtual void handleEvent() = 0;

	// compareTo - used to order Events.
	int compareTo(ListItem *other);

	virtual void print();
	int getTime();

}; // class Event
