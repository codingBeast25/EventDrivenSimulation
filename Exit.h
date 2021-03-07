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