/**
    File        : Timer.cpp

    Project     : observer-pattern-evolution-refact-04

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#include "../include/Timer.h"

Timer::Timer(INotifier* notifier)
{
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;
    m_notifier = notifier;
}

Timer::Timer(int hours, int minutes, int seconds, INotifier* notifier)
{
    m_hours = hours;
    m_minutes = minutes;
    m_seconds = seconds;
    m_notifier = notifier;
}

Timer::~Timer()
{
    do
    {
        m_tick();
        #ifdef __unix__
            sleep(1);
            system("clear");
        #elif defined(_WIN32) || defined(WIN32)
            Sleep( 1000 );
            system("cls");
        #endif // defined
    }
    while(m_startState);
}

void Timer::setHours(int hours)
{
    if(hours > 23)
    {
        std::cout << "Warning: the maximum allowable is 23 hours" << endl;
        hours = 23;
    }
    m_hours = hours;
}

int Timer::getHours()
{
    return m_hours;
}

void Timer::setMinutes(int minutes)
{
    if(minutes > 59)
    {
        cout << "Warning: the maximum allowable is 59 minutes" << endl;
        minutes = 59;
    }
    m_minutes = minutes;
}

int Timer::getMinutes()
{
    return m_minutes;
}

void Timer::setSeconds(int seconds)
{
    if(seconds > 59)
    {
        cout << "Warning: the maximum allowable is 59 seconds" << endl;
        seconds = 59;
    }
    m_seconds = seconds;
}

int Timer::getSeconds()
{
    return m_seconds;
}

void Timer::start()
{
    m_startState = true;
}

void Timer::stop()
{
    m_startState = false;
}

void Timer::m_tick()
{
    m_seconds++;
    if (m_seconds > 59)
    {
        m_seconds = 0;
        m_minutes++;

        if (m_minutes > 59)
        {
              m_minutes = 0;
              m_hours++;

              if (m_hours > 23)
              {
                    m_hours = 0;
              }
        }
    }
    m_notifier->notify();
}

