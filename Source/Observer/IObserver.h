#pragma once

namespace designpatterns
{

class IObserver
{
public:
	virtual void Update(float temperature) = 0;

public:
    virtual ~IObserver()
    {}
};

}