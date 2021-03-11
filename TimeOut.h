/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: TimeOut Event defination.
*/
#pragma once
#include "Event.h"
class Simulation;
class Process;

class TimeOut : public Event
{

public:
    //constructor
    TimeOut(int time, Process *pro, Simulation *simul);
    //print the details
    void print();
    //handles the event call
    void handleEvent();
};