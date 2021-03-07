#pragma once
#include "Event.h"
class Simulation;
class Process;

class StartIo : public Event
{
public:
    StartIo(int time, Process *pro, Simulation *simul);
    void print();
    void handleEvent();
};