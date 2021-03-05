#pragma once
#include "Event.h"
class Simulation;
class Process;

class CompleteCpu : public Event
{

public:
    CompleteCpu(int time, Process *pro, Simulation *simul);
    void print();
    void handleEvent();
};