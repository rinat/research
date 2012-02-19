#pragma once

#include "ISubject.h"

namespace designpatterns
{

class IObserver;

class Sensor : public ISubject
{
public:
    Sensor()
        : _temperature(0.0)
    {}

    void SetTemperature(float newTemperature);
    float GetTemperature() const;

    void TemperatureChanged();

public:
    /*virtual*/ void RegisterObserver(IObserver& observer);
    /*virtual*/ void RemoveObserver(IObserver& observer);
    /*virtual*/ void NotifyObservers() const;

private:
    float _temperature;
    std::list<IObserver*> _observers;

private:
    Sensor(const Sensor&);
    void operator =(const Sensor&);
};

}