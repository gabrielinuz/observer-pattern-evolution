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

#include "../include/Ascriber.h"

IAscriber* Ascriber::m_instance = 0;

IAscriber* Ascriber::getInstance()
{
    if(m_instance == 0)
    {
        m_instance = new Ascriber();
    }
    return m_instance;
}

Ascriber::Ascriber(){}

Ascriber::~Ascriber(){}

void Ascriber::attach(IObserver* observer)
{
    m_observersList.push_front(observer);
}

void Ascriber::detach(IObserver* observer)
{
    m_observersList.remove(observer);
}

void Ascriber::notify()
{
    list<IObserver*>::iterator it;

    for (it =  m_observersList.begin() ; it !=  m_observersList.end(); ++it)
    {
       (*it)->update();
    }
}


