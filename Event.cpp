#include "Event.h"
#include "Process.h"
#include <iostream>
using namespace std;

/**** Event implementation */
Event::Event(int theTime, Process *theProcess, Simulation *theSim)
	: eventTime(theTime), process(theProcess), sim(theSim) {}
Event::Event() {}

int Event::compareTo(ListItem *other)
{
	int boolean = 0; //false

	Event *otherEvent = dynamic_cast<Event *>(other);
	if (otherEvent != nullptr)
	{
		if ((this->getTime()) < (otherEvent->getTime()))
		{
			boolean = 1;
		}
		else if ((this->getTime()) == (otherEvent->getTime()))
		{
			if (this->getProcess()->getId() < otherEvent->getProcess()->getId())
			{
				boolean = 1;
			}
		}
		}
	return boolean;
}

int Event::getTime()
{
	return this->eventTime;
}

Process *Event::getProcess()
{
	return process;
}

Simulation *Event::getSim()
{
	return sim;
}

void Event::print()
{
	cout << "EVENT METHOD PRINT" << endl;
}
