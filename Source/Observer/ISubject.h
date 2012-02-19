#pragma once

namespace designpatterns
{

class IObserver;

class ISubject
{
public:
    virtual void RegisterObserver(IObserver& observer) = 0;
    virtual void RemoveObserver(IObserver& observer) = 0;
    virtual void NotifyObservers() const = 0;

public:
    virtual ~ISubject()
    {}
};

}