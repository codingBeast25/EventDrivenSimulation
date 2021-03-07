#pragma once
#include "Event.h"
class Simulation;
class Process;

class Arrival : public Event
{
    /*
private:
    int arrTime;
    Process *currProcess;
    Simulation *sim;
*/
public:
    Arrival(int time, Process *pro, Simulation *simul);
    void print();
    void handleEvent();
};