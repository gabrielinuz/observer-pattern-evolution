/**
    File        : TimerFactory.cpp

    Project     : observer-pattern-evolution-refact-03

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/


#include "../include/INotifier.h"
#include "../include/TimerFactory.h"
#include "../include/ChangeManager.h"
#include "../include/Timer.h"

TimerFactory::TimerFactory() {}
TimerFactory::~TimerFactory() {}

ITimer* TimerFactory::create(string id)
{
    INotifier* notifier = ChangeManager::getInstance();
    if( id ==  "cpp-timer" )
    {
        return Timer::initWith(notifier);
    }

    return Timer::initWith(notifier);
}
