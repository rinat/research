#pragma once

namespace designpatterns
{

class IDisplayElement
{
public:
    virtual void Display() const = 0;

public:
    virtual ~IDisplayElement()
    {}
};

}