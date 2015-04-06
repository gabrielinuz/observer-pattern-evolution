/**
    File        : WidgetFactory.h

    Project     : observer-pattern-evolution-refact-03

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H

#include <string>
#include "ITimer.h"
#include "IAscriber.h"
#include "IWidget.h"

using namespace std;

class WidgetFactory
{
    public:
        WidgetFactory();
        virtual ~WidgetFactory();
        static IWidget* create(string id);
};

#endif // WIDGETFACTORY_H
