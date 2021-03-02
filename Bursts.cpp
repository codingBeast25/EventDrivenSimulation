#include "Bursts.h"

Bursts::Bursts(int num)
{
    currBurst = num;
}

int Bursts::getBurst()
{
    return currBurst;
}

void Bursts::setBurst(int num)
{
    currBurst = num;
}

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