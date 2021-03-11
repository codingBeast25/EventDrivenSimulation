/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: Start cpu implementation which checks if current process needs more cpu time then the allocated time and schedule timeout event or if dosent need more than allocated time then scheudle complete cpu event.
*/
#pragma once
#include "Event.h"
class Simulation;
class Process;

class StartCpu : public Event
{

public:
    //constructor
    StartCpu(int time, Process *pro, Simulation *simul);
    //print the details
    void print();
    //handles the main processing fo this event
    void handleEvent();
};