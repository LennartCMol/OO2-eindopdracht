#pragma once
#include <iostream>

class Application
{
public:
	Application();
	~Application();
	void run();
	
private:
	template <typename T>
	void checkInput(T variableType, int min, int max);
	double latitude = 45.000;
	double langitude = 8.000;
	int peakPower = 1;
	const int loss = 14;
	int angle = 0;
	int aspect = 0;
	int energyUsage = 4000;
};

#include "Application.hpp"