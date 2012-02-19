#pragma once

#include "IObserver.h"
#include "IDisplayElement.h"

namespace designpatterns
{

class ISubject;

class FrontPanel : private IObserver, private IDisplayElement
{
public:
    explicit FrontPanel(ISubject& temperatureSensor);

    ~FrontPanel();

public:
    /*virtual*/ void Update(float temperature);

public:
    /*virtual*/ void Display() const;

private:
    ISubject *_subject;
    float _temperature;

private:
    FrontPanel(const FrontPanel&);
    void operator =(const FrontPanel&);
};

}