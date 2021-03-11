/*
*Name : Kabir Bhakta    Student Number: 7900098
*Purpose : Exit implementation which gathers all the statistics of the process and store it in to be printed at the end of the execution of the entire simulation
*/
#pragma once
#include "Event.h"
class Simulation;
class Process;

class Exit : public Event
{

public:
    Exit(int time, Process *pro, Simulation *simul);
    void print();
    void handleEvent();
};