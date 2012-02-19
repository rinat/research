// Observer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Sensor.h"
#include "ControlPanel.h"
#include "FrontPanel.h"

int _tmain(int argc, _TCHAR* argv[])
{
    using namespace designpatterns;

    Sensor sensor;
    ControlPanel otherDisplay(sensor);
    FrontPanel FrontPanel(sensor);

    sensor.SetTemperature(20.1f);
    sensor.SetTemperature(25.4f);
    sensor.SetTemperature(29.2f);

	return 0;
}

