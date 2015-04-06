/**
    File        : TimerFactory.h

    Project     : observer-pattern-evolution-refact-03

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#ifndef TIMERFACTORY_H
#define TIMERFACTORY_H

#include <string>
#include "../include/ITimer.h"

using namespace std;

class TimerFactory
{
    public:
        TimerFactory();
        virtual ~TimerFactory();
        static ITimer* create(string id);
};

#endif // TIMERFACTORY_H
