/**
    File        : WidgetFactory.cpp

    Project     : observer-pattern-evolution-refact-03

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/


#include "../include/WidgetFactory.h"

#include "../include/TimerFactory.h"
#include "../include/ChangeManager.h"
#include "../include/AnalogClock.h"
#include "../include/DigitalClock.h"

WidgetFactory::WidgetFactory() {}

WidgetFactory::~WidgetFactory() {}

IWidget* WidgetFactory::create(string id)
{
    ITimer* timer = TimerFactory::create("cpp-timer");
    IAscriber* ascriber = ChangeManager::getInstance();

    if( id ==  "analog-clock" )
    {
        return new AnalogClock(timer, ascriber);
    }

    if( id ==  "digital-clock" )
    {
        return new DigitalClock(timer, ascriber);
    }

    return new DigitalClock(timer, ascriber);
}
