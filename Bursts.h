#pragma once
#include "ListItem.h"
class Bursts : public ListItem
{
private:
    int currBurst;

public:
    Bursts(int num);
    int getBurst();
    void setBurst(int num);
    int compareTo(ListItem *other);
};