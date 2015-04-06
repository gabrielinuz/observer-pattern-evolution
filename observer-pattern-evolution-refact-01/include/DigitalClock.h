/**
    File        : DigitalClock.h

    Project     : observer-pattern-evolution-refact-01

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <iostream>
#include <string>
#include "IWidget.h"
#include "ITimer.h"
#include "IObserver.h"
#include "IAscriber.h"

using namespace std;

class DigitalClock : public IWidget, public IObserver
{
    public:
        DigitalClock(ITimer* timer, IAscriber* ascriber);
        virtual ~DigitalClock();
        void update();
        void draw();

    private:
        ITimer* m_timer;
        IAscriber* m_ascriber;
        int m_hours;
        int m_minutes;
        int m_seconds;
};

#endif // DIGITALCLOCK_H
