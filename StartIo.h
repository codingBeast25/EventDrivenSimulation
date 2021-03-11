/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: Start I/O event on a process
*/
#pragma once
#include "Event.h"
class Simulation;
class Process;

class StartIo : public Event
{
public:
    //constructor
    StartIo(int time, Process *pro, Simulation *simul);
    //print the details
    void print();
    //handle event
    void handleEvent();
};