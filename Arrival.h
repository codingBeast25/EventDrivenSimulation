#pragma once
#include "Event.h"
class Simulation;

class Arrival : public Event
{

private:
    int arrTime;
    Queue *cQueue;
    Queue *iQueue;

public:
    Arrival(int time, Queue *CPUQ, Queue *IOQ);

    void handleEvent();
    int getTime();
};