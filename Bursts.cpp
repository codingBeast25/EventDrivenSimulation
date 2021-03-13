/*
*Name: Kabir Bhakta		Student Number: 7900098
*Purpose: Bursts Implementation. Note that the compareTo method is of no use because we dont use burst in priority queue.
*/
#include "Bursts.h"

//Constructor
Bursts::Bursts(int num)
{
    currBurst = num;
}

//Return the current Bursts
int Bursts::getBurst()
{
    return currBurst;
}

//sets the current bursts
void Bursts::setBurst(int num)
{
    currBurst = num;
}

//useless method useed nowhere becasue we are using this in queue and not in PQ
int Bursts::compareTo(ListItem *other)
{
    int boolean = 0;
    Bursts *otherBurst = dynamic_cast<Bursts *>(other);
    if (otherBurst != nullptr)
    {
        if ((this->getBurst()) > (otherBurst->getBurst()))
        {
            boolean = 1;
        }
        else if ((this->getBurst()) < (otherBurst->getBurst()))
        {
            boolean = -1;
        }
    }
    return boolean;
}