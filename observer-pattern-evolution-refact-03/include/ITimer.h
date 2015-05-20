/**
    File        : ITimer.h

    Project     : observer-pattern-evolution-refact-03

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#ifndef ITIMER_H
#define ITIMER_H

class ITimer
{
    public:
        virtual ~ITimer() {}

        virtual void setHours( int hours ) = 0;
        virtual void setMinutes( int minutes ) = 0;
        virtual void setSeconds( int seconds ) = 0;

        virtual int getHours() = 0;
        virtual int getMinutes() = 0;
        virtual int getSeconds() = 0;
};

#endif // ITIMER_H
