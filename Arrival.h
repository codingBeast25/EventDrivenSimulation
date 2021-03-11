/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: Arrvial Event defination.
*/
#pragma once
#include "Event.h"
class Simulation;
class Process;

class Arrival : public Event
{

public:
    Arrival(int time, Process *pro, Simulation *simul);
    void print();
    void handleEvent();
};