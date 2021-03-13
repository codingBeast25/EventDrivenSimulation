/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: Storing Burst in Process's CPU/IO queue as a series of bursts
*/
#pragma once
#include "ListItem.h"
class Bursts : public ListItem
{
private:
    int currBurst;

public:
    //Constructor
    Bursts(int num);
    //get the current Burst
    int getBurst();
    //set the current bursts
    void setBurst(int num);
    //compareTo just to override noting used
    int compareTo(ListItem *other);
};