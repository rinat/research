#include "stdafx.h"

#include "ControlPanel.h"
#include "ISubject.h"

namespace designpatterns
{

ControlPanel::ControlPanel(ISubject& temperatureSensor)
    : _subject(&temperatureSensor)
    , _temperature(0.0)
{
    _subject->RegisterObserver(*this);
}

ControlPanel::~ControlPanel()
{
    _subject->RemoveObserver(*this);
}

void ControlPanel::Display() const
{
    std::cout.setf( std::ios::showpoint );
    std::cout.precision(3);
    std::cout << "Other Display: " << _temperature << std::endl;
}

void ControlPanel::Update(float temperature)
{
    _temperature = temperature;
    Display();
}

}