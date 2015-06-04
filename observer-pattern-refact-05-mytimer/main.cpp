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

#ifdef __unix__
    #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif // defined

#include <iostream>

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

    timer->setSeconds(56);
    timer->setMinutes(59);
    timer->setHours(23);

    IAscriber* ascriber = ChangeManager::getInstance();
    AnalogClock* analogClock1 = new AnalogClock(timer, ascriber);
    DigitalClock* digitalClock1 = new DigitalClock(timer, ascriber);

    while(1)
    {
        timer->tick();
        #ifdef __unix__
            sleep(1);
            system("clear");
        #elif defined(_WIN32) || defined(WIN32)
            Sleep( 1000 );
            system("cls");
        #endif // defined
    }

    delete timer;
    delete analogClock1;
    delete digitalClock1;
    return 0;
}
