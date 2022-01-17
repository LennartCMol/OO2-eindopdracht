#pragma once
#include <iostream>
#include "Webclient.h"
#include "Parser.h"
#include "Calculator.h"

class Application
{
public:
	Application();
	~Application();
	void run();
	
private:
	template <typename T>
	T checkInput(T variableType, int min, int max);
	double latitude = 51.688307;
	double langitude = 5.286983;
	double peakPower = 0.350;
	const double loss = 1.2;
	int angle = 40;
	int aspect = -45;
	int energyUsage = 4000;
	std::map<int, double> kWhPerMonth;
};

#include "Application.hpp"