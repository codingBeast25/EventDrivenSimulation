/*
*Name: Kabir Bhakta     Student Number: 7900098
*Purpose: Test for our data structure and Our other implementation
*/
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Simulation.h"
#include "ParentQueue.h"
#include "PriorityQueue.h"
#include "Process.h"
#include "Event.h"
#include "StartCpu.h"
#include "Arrival.h"
#include "TimeOut.h"
#include "CompleteCpu.h"
#include "StartIo.h"
#include "CompleteIo.h"
#include "Exit.h"

Queue *c1;
Queue *c2;
Queue *i1;
Queue *i2;
Process *p1 = new Process(1, 5, c1, i1);
Process *p2 = new Process(2, 5, c2, i2);
Simulation *newSim = new Simulation;

TEST_CASE("->Testing IsEmpty() method.")
{
    PriorityQueue *list = new PriorityQueue;
    REQUIRE(list->getSize() == 0);
    REQUIRE(list->isEmpty());
    REQUIRE(list->getTop() == nullptr);

    //add new event to list
    Event *newEvent = new Arrival(1, p1, newSim);
    list->enqueue(newEvent);

    //test if it is still empty or not, should be emptyy
    REQUIRE(!list->isEmpty());
    REQUIRE(list->getSize() == 1);
}
TEST_CASE("->Testing getSize()")
{
    PriorityQueue *list = new PriorityQueue;
    Event *newEvent = new StartCpu(1, p2, newSim);

    REQUIRE(list->getSize() == 0);

    list->enqueue(newEvent);

    REQUIRE(list->getSize() == 1);

    //comparing the only item there in list
    REQUIRE(dynamic_cast<Event *>(list->getTop())->compareTo(newEvent) == 0);

    Event *e2 = new CompleteCpu(5, p2, newSim);
    list->enqueue(e2);
    REQUIRE(list->getSize() == 2);

    //lets dequeue and check the size again
    list->dequeue();
    REQUIRE(list->getSize() == 1);

    //removed start cpu event and now will compare completeCpu with start cpu
    REQUIRE(dynamic_cast<Event *>(list->getTop())->compareTo(newEvent) == 0);
    REQUIRE(list->getSize() == 1);
}

TEST_CASE("->Testing Dequeue().")
{
    PriorityQueue *list = new PriorityQueue;
    Event *e1 = new StartCpu(1, p2, newSim);
    Event *e2 = new CompleteIo(10, p1, newSim);
    Event *e3 = new StartIo(9, p2, newSim);
    Event *e4 = new Exit(10, p1, newSim);

    list->enqueue(e1);
    list->enqueue(e2);
    list->enqueue(e3);
    list->enqueue(e4);

    REQUIRE(list->getSize() == 4);

    //when we dequeue from list we should get e1 as it has highest priority in our priority queue
    REQUIRE(dynamic_cast<Event *>(list->dequeue())->compareTo(e1) == 0);
    REQUIRE(list->getSize() == 3);

    //now when we dequeue we should get e3 as it has current highest priority in our priority queue
    REQUIRE(dynamic_cast<Event *>(list->dequeue())->compareTo(e3) == 0);
    REQUIRE(list->getSize() == 2);

    //now when we dequeue we should get e2 as both e2 as well as e4 have same arriavl time but e2 was enqueued first
    REQUIRE(dynamic_cast<Event *>(list->dequeue())->compareTo(e2) == 0);
    REQUIRE(list->getSize() == 1);

    //now the only element left in the list e4
    REQUIRE(dynamic_cast<Event *>(list->dequeue())->compareTo(e4) == 0);
    REQUIRE(list->getSize() == 0);

    REQUIRE(list->isEmpty());
}

TEST_CASE("->Testing getTop().")
{
    PriorityQueue *list = new PriorityQueue;
    Event *e1 = new StartCpu(1, p2, newSim);
    Event *e2 = new CompleteIo(10, p1, newSim);
    Event *e3 = new StartIo(9, p2, newSim);
    Event *e4 = new Exit(10, p1, newSim);

    list->enqueue(e1);
    list->enqueue(e2);
    list->enqueue(e3);
    list->enqueue(e4);
    /*
        list : e1 -> e3 -> e2 -> e4
             (top)
    */

    REQUIRE(list->getSize() == 4);
    //current top of the list = e1
    REQUIRE(dynamic_cast<Event *>(list->getTop())->compareTo(e1) == 0);
    list->dequeue();

    /*
        list : e3 -> e2 -> e4
             (top)
    */
    REQUIRE(dynamic_cast<Event *>(list->getTop())->compareTo(e3) == 0);
    list->dequeue();

    /*
        list : e2 -> e4
             (top)
    */
    REQUIRE(dynamic_cast<Event *>(list->getTop())->compareTo(e2) == 0);
}

TEST_CASE("->Testing Enqueue.")
{
    PriorityQueue *list = new PriorityQueue;
    Event *e1 = new Arrival(1, p2, newSim);
    Event *e2 = new Arrival(9, p2, newSim);
    Event *e3 = new StartIo(9, p1, newSim);
    Event *e4 = new TimeOut(1, p1, newSim);

    list->enqueue(e4);
    list->enqueue(e1);
    list->enqueue(e2);
    list->enqueue(e3);

    /*
    OUr Priority queue enqueue works on several conditions:
    1. If arrival time of two events is same then event with lower process id is inserted first
    2. If two events are Arrival and TimeOut with same arrival time then Arrival event should be inserted first regardless of the process id
    Hence, our list should look like this : e1 -> e4 -> e3 -> e2
    */
    REQUIRE(dynamic_cast<Event *>(list->dequeue())->compareTo(e1) == 0);
    REQUIRE(dynamic_cast<Event *>(list->dequeue())->compareTo(e4) == 0);
    REQUIRE(dynamic_cast<Event *>(list->dequeue())->compareTo(e3) == 0);
    REQUIRE(dynamic_cast<Event *>(list->dequeue())->compareTo(e2) == 0);
}