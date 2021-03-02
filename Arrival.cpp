#include "Arrival.h"
#include "Queue.h"

Arrival::Arrival(int arriveT, Queue *cQueue, Queue *iQueue)
{
    arrTime = arriveT;
    this->cQueue = cQueue;
    this->iQueue = iQueue;
}

int Arrival::getTime()
{
    return this->arrTime;
}

void Arrival::handleEvent()
{
}
