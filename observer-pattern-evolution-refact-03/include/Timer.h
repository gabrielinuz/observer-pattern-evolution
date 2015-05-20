/**
    File        : Timer.h

    Project     : observer-pattern-evolution-refact-03

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#ifndef TIMER_H
#define TIMER_H

#include "ITimer.h"
#include "INotifier.h"
#include <chrono>
#include <thread>

using namespace std;

class Timer : public ITimer
{
    public:
        Timer(INotifier* notifier);
        Timer(int hours, int minutes, int seconds, INotifier* notifier);
        virtual ~Timer();

        void setHours(int hours);
        int getHours();
        void setMinutes(int minutes);
        int getMinutes();
        void setSeconds(int seconds);
        int getSeconds();

    private:
        int m_hours;
        int m_minutes;
        int m_seconds;
        void m_tick();

        INotifier* m_notifier;

};

#endif // TIMER_H
