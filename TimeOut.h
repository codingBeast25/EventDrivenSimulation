#pragma once
#include "Event.h"
class Simulation;
class Process;

class TimeOut : public Event
{

public:
    TimeOut(int time, Process *pro, Simulation *simul);
    void print();
    void handleEvent();
};