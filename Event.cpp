/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: All event related needs are handled here.
*/
#include "Event.h"
#include "TimeOut.h"
#include "Arrival.h"
#include "Process.h"
#include <iostream>
using namespace std;

/**** Event implementation */
//constructor
Event::Event(int theTime, Process *theProcess, Simulation *theSim)
	: eventTime(theTime), process(theProcess), sim(theSim) {}

//compare current event with other event. If both the events are same then 0 is returned.
int Event::compareTo(ListItem *other)
{
	int boolean = 0; //false

	Event *otherEvent = dynamic_cast<Event *>(other);
	if (otherEvent != nullptr)
	{
		if ((this->getTime()) < (otherEvent->getTime())) //if current event came before other event
		{
			boolean = 1;
		}
		else if ((this->getTime()) == (otherEvent->getTime())) //if current event time is equal to other event time
		{
			//check to see if this event is Arrival or not if it then set the boolean to 1 becasue arrival should be dealt with first tehn timeout
			if (dynamic_cast<Arrival *>(this) && dynamic_cast<TimeOut *>(otherEvent))
			{
				boolean = 1;
			}
			//check to see if this event is Timeout or not if it then set the boolean to 0
			else if (dynamic_cast<Arrival *>(otherEvent) && dynamic_cast<TimeOut *>(this))
			{
				boolean = 0;
			}

			else if (this->getProcess()->compareTo(otherEvent->getProcess()))
			{
				//need process compareto method which compares on basis of id
				boolean = 1;
			}
		}
	}
	return boolean;
}

//get arriavl time of event
int Event::getTime()
{
	return this->eventTime;
}

//get the process of this event
Process *Event::getProcess()
{
	return process;
}
//get simulation
Simulation *Event::getSim()
{
	return sim;
}

void Event::print()
{
	cout << "EVENT METHOD PRINT" << endl;
}
