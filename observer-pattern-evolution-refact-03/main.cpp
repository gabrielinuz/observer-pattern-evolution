/**
    File        : main.cpp

    Project     : observer-pattern-evolution-refact-03

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

#include "include/TimerFactory.h"
#include "include/WidgetFactory.h"
#include "include/ITimer.h"
#include "include/IWidget.h"

using namespace std;

int main()
{
    ITimer* timer = TimerFactory::create("cpp-timer");

    WidgetFactory::create("analog-clock");
    WidgetFactory::create("digital-clock");

    while(1)
    {
        timer->tick();
        this_thread::sleep_for (chrono::seconds(1));
    }

    return 0;
}
