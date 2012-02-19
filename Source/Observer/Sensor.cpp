#include "stdafx.h"

#include "Sensor.h"
#include "IObserver.h"

namespace designpatterns
{

void Sensor::SetTemperature(float newTemperature)
{
    _temperature = newTemperature;
    TemperatureChanged();
}

float Sensor::GetTemperature() const
{
    return _temperature;
}

void Sensor::TemperatureChanged()
{
    NotifyObservers();
}

void Sensor::RegisterObserver(IObserver& observer)
{
    _observers.push_back(&observer);
}

void Sensor::RemoveObserver(IObserver& observer)
{
    _observers.remove(&observer);
}

void Sensor::NotifyObservers() const
{
    for (auto iterator = _observers.cbegin(); _observers.cend() != iterator; ++iterator)
    {
        auto observer = *iterator;
        observer->Update(_temperature);
    }
}

}