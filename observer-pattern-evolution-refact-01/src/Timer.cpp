/**
    File        : Timer.cpp

    Project     : observer-pattern-evolution-refact-01

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#include "../include/Timer.h"

Timer::Timer(IAscriber* ascriber)
{
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;
    m_ascriber = ascriber;
}

Timer::Timer(int hours, int minutes, int seconds, IAscriber* ascriber)
{
    m_hours = hours;
    m_minutes = minutes;
    m_seconds = seconds;
    m_ascriber = ascriber;
}

Timer::~Timer(){}

void Timer::setHours(int hours)
{
    m_hours = hours;
}

int Timer::getHours()
{
    return m_hours;
}

void Timer::setMinutes(int minutes)
{
    m_minutes = minutes;
}

int Timer::getMinutes()
{
    return m_minutes;
}

void Timer::setSeconds(int seconds)
{
    m_seconds = seconds;
}

int Timer::getSeconds()
{
    return m_seconds;
}

void Timer::tick()
{

    m_seconds++;
    if(m_seconds == 60)
    {
        m_seconds = 0;
        m_minutes++;
        if(m_minutes == 60)
        {
            m_seconds = 0;
            m_minutes = 0;
            m_hours++;
            if(m_hours == 24)
            {
                m_seconds = 0;
                m_minutes = 0;
                m_hours = 0;
            }
        }

    }

    m_ascriber->notify();
}

