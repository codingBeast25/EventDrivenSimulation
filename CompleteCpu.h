/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: Complete cpu event on a process
*/
#pragma once
#include "Event.h"
class Simulation;
class Process;

class CompleteCpu : public Event
{

public:
    //constructor
    CompleteCpu(int time, Process *pro, Simulation *simul);
    //prints the details
    void print();
    //handles the event
    void handleEvent();
};