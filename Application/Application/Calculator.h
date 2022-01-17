#pragma once
#include <map>
#include <atomic>
#include <thread>
#include <vector>
#include <iostream>
#include <string>

class Calculator
{
public:
	Calculator();
	~Calculator();
	void calculateTotalPanels(std::map<int, double>, int);
	void calculatePanelPerMonth(double);

private:
	int energyUsagePerMonth;
	std::atomic<double> totalPanels;
};


