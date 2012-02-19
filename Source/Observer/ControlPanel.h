#pragma once

#include "IObserver.h"
#include "IDisplayElement.h"

namespace designpatterns
{

class ISubject;

class ControlPanel : private IObserver, private IDisplayElement
{
public:
    explicit ControlPanel(ISubject& temperatureSensor);

    ~ControlPanel();

public:
    /*virtual*/ void Update(float temperature);

public:
    /*virtual*/ void Display() const;

private:
    ISubject *_subject;
    float _temperature;

private:
    ControlPanel(const ControlPanel&);
    void operator =(const ControlPanel&);
};

}