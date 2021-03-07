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