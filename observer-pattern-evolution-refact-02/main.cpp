/**
    File        : main.cpp

    Project     : observer-pattern-evolution-refact-02

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#include <iostream>
#include <chrono>
#include <thread>

#include "include/ITimer.h"
#include "include/IAscriber.h"
#include "include/INotifier.h"

#include "include/Timer.h"
#include "include/ChangeManager.h"
#include "include/AnalogClock.h"
#include "include/DigitalClock.h"

using namespace std;

int main()
{
    INotifier* notifier = ChangeManager::getInstance();
    ITimer* timer = new Timer(notifier);

    IAscriber* ascriber = ChangeManager::getInstance();
    new AnalogClock(timer, ascriber);
    new DigitalClock(timer, ascriber);

    while(1)
    {
        timer->tick();
        this_thread::sleep_for (chrono::seconds(1));
    }

    delete timer;

    return 0;
}
