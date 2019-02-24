//
//  Timer.h
//  Project 1
//
//  Created by Eric Hyson on 2/8/19.
//  Copyright © 2019 Eric Hyson. All rights reserved.
//

#ifndef Timer_h
#define Timer_h

#include "OrderedList.h"
#include "MTFList.h"
#include <cstdlib>
#include <ctime>

using namespace std;


class Timer{
    
public:
    Timer();
    ~Timer() {};
    
    void setStart( clock_t st);
    void setEnd( clock_t ed );
    clock_t getStart();
    clock_t getEnd();
    double getElapsed();

private:
    clock_t start;
    clock_t end;
};



/*****************************************************************************
 *                            constructor                                    *
 ****************************************************************************/

Timer::Timer()
{
    start = 0;
    end = 0;
}



/****************************************************************************
 *                            public methods                                *
 ****************************************************************************/


void Timer::setStart( clock_t st )
{
    start = st;
}




void Timer::setEnd( clock_t ed )
{
    end = ed;
}



clock_t Timer::getStart()
{
    return start;
}


clock_t Timer::getEnd()
{
    return end;
}



double Timer::getElapsed()
{
    return static_cast<double>( (end - static_cast<double>(start))/CLOCKS_PER_SEC );
}








#endif /* Timer_h */
