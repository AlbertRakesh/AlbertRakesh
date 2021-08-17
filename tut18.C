#include "TStopwatch.h"
#include "TRandom2.h"

#include<iostream>

using namespace std;


void tut18()
{

    TStopwatch t;//to know the time it takes to execute

    TRandom2 *r = new TRandom2();
    double x = 0;

    for (int i=0; i<1e9; i++)
    {
       x+=r->Rndm();//adding the random number and storing it in x;
    }

    cout << x << endl;

    t.Print();//printing t
}