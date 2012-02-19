#include "stdafx.h"

#include "FrontPanel.h"
#include "ISubject.h"

namespace designpatterns
{

FrontPanel::FrontPanel(ISubject& temperatureSensor)
    : _subject(&temperatureSensor)
    , _temperature(0.0)
{
    _subject->RegisterObserver(*this);
}

FrontPanel::~FrontPanel()
{
    _subject->RemoveObserver(*this);
}

void FrontPanel::Display() const
{
    std::cout.setf( std::ios::showpoint );
    std::cout.precision(3);
    std::cout << "Temperature Display: "	<< _temperature << std::endl;
}

void FrontPanel::Update(float temperature)
{
    _temperature = temperature;
    Display();
}

}