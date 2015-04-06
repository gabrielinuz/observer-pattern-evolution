/**
    File        : ChangeManager.h

    Project     : observer-pattern-evolution-refact-02

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#ifndef CHANGEMANAGER_H
#define CHANGEMANAGER_H

#include "IAscriber.h"
#include "INotifier.h"
#include "IObserver.h"
#include <list>

using namespace std;

class ChangeManager : public IAscriber, public INotifier
{

    public:
        static ChangeManager* getInstance();
        virtual ~ChangeManager();

        void attach(IObserver* observer);

        void detach(IObserver* observer);

        void notify( void );

    protected:
        ChangeManager(void);

    private:
        static ChangeManager* m_instance;
        list<IObserver*> m_observersList;
};

#endif // CHANGEMANAGER_H
