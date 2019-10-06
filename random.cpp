#include "random.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

random::random()
{
    //nothing need to be here.
}

void random::seed()
{
    srand(time(NULL));
}

int random::next(int lo, int hi)
{
    int r = rand()%(hi - lo + 1) + lo;

    return r;
}
