/**
    File        : Ascriber.h

    Project     : observer-pattern-evolution-refact-01

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#ifndef ASCRIBER_H
#define ASCRIBER_H

#include "IAscriber.h"
#include "IObserver.h"
#include <list>

using namespace std;

class Ascriber : public IAscriber
{
    public:
        static IAscriber* getInstance();

        virtual ~Ascriber();

        void attach(IObserver* observer);

        void detach(IObserver* observer);

        void notify();

    protected:
        Ascriber();

    private:
        static IAscriber* m_instance;
        list<IObserver*> m_observersList;
};
#endif // ASCRIBER_H


