/*
*Name : Kabir Bhakta    Student Number: 7900098
*Purpose : CompleteIo implementation which checks if there is more burst to process in the series or not. IF there is then schedule the next cpu start event or schedule the next Io start fromIOQ
*/
#pragma once
#include "Event.h"
class Simulation;
class Process;

class CompleteIo : public Event
{

public:
    CompleteIo(int time, Process *pro, Simulation *simul);
    void print();
    void handleEvent();
};