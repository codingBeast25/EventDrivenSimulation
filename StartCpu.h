#pragma once
#include "Event.h"
class Simulation;
class Process;

class StartCpu : public Event
{

public:
    StartCpu(int time, Process *pro, Simulation *simul);
    void print();
    void handleEvent();
    int getTime();
};