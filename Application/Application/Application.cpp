#include "Application.h"

Application::Application()
{
}

Application::~Application()
{
}

void Application::run() {
    std::cout << "Enter Latitude (degrees):" << std::endl;
    Application::checkInput<double>(latitude, -90, 90);
    std::cout << "Enter langitude (degrees):" << std::endl;
    checkInput<double>(langitude, -180, 180);
    std::cout << "Enter Nominal power of the PV system (c-Si) (kWp) (min 0. max 500.): " << std::endl;
    checkInput<int>(peakPower, 0, 500);
    std::cout << "Enter Fixed slope of modules (degrees) (min 0. max 90):" << std::endl;
    checkInput<int>(angle, 0, 90);
    std::cout << "Enter Orientation (azimuth) of modules (degrees) (min -180. max 180.):" << std::endl;
    checkInput<int>(aspect, -180, 180);
    std::cout << "Enter energy usage (kWh/year) (min 0. max 20000.)" << std::endl;
    checkInput<int>(energyUsage, 0, 20000);
}