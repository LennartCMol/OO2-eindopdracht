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

private:
	int energyUsagePerMonth = 0;
	std::atomic<double> totalPanels;
	void calculatePanelPerMonth(double);
};


