#include "Calculator.h"


Calculator::Calculator()
{

}

Calculator::~Calculator()
{
}

void Calculator::calculateTotalPanels(std::map<int, double> kWhPerMonth, int energyUsagePerYear) {
	energyUsagePerMonth = energyUsagePerYear / 12;

	std::vector<std::thread> threads;

	// create thread for all months and put them into vector
	for (int i = 1; i < kWhPerMonth.size() + 1; i++) {
		threads.push_back(std::thread (&Calculator::calculatePanelPerMonth, this, kWhPerMonth[i]));
	}

	// join all threads in vector
	for (std::thread& thread : threads) {
		thread.join();
	}

	int avgPanels = (int) (totalPanels / 12);
	double kWhPerYearDouble = 0;

	// Get sum of energy for one solar panel for one year
	for (int i = 1; i < kWhPerMonth.size() + 1; i++) {
		kWhPerYearDouble = kWhPerYearDouble + kWhPerMonth[i];
	}
	int kWhPerYear = (int)kWhPerYearDouble;

	int total = kWhPerYear * avgPanels;

	// Correct probable overshoot by subtracting a solar panel and checking if the energy is still higher than needed.
	while ((total - kWhPerYear) > energyUsagePerYear) {
		avgPanels -= 1;
		total = kWhPerYear * avgPanels;
	}

	std::cout << "Solar panels required: " << std::to_string(avgPanels) << std::endl;

	int kWhDeviation = total - energyUsagePerYear;

	std::cout << "Deviation in kWh: " << std::to_string(kWhDeviation) << std::endl;

	double kWhDeviationPercentage =  ((double) total / (double) energyUsagePerYear);

	std::cout << "Deviation in %: " << std::to_string(kWhDeviationPercentage) << "%" << std::endl;
}

void Calculator::calculatePanelPerMonth(double kWhPerMonth) {
	totalPanels = totalPanels + (energyUsagePerMonth / kWhPerMonth);
}

