#include "Application.h"

Application::Application()
{
}

Application::~Application()
{
}

void Application::run() {
    std::cout << "Enter Latitude (degrees) (min 90. max 90.):" << std::endl;
    latitude = Application::checkInput<double>(latitude, -90, 90);
    std::cout << "Enter langitude (degrees) (min -180. max 180.):" << std::endl;
    langitude = checkInput<double>(langitude, -180, 180);
    std::cout << "Enter Nominal power of the PV system (c-Si) (kWp) (min 0. max 500.): " << std::endl;
    peakPower = checkInput<int>(peakPower, 0, 500);
    std::cout << "Enter Fixed slope of modules (degrees) (min 0. max 90):" << std::endl;
    angle = checkInput<int>(angle, 0, 90);
    std::cout << "Enter Orientation (azimuth) of modules (degrees) (min -180. max 180.):" << std::endl;
    aspect = checkInput<int>(aspect, -180, 180);
    std::cout << "Enter energy usage (kWh/year) (min 0. max 20000.)" << std::endl;
    energyUsage = checkInput<int>(energyUsage, 0, 20000);

    Webclient client;

    std::string rawData = client.requestData(latitude, langitude, peakPower, loss, angle, aspect);
    std::cout << rawData;
    
    Parser parser;

    kWhPerMonth = parser.Parse(rawData);
    for (int i = 1; i < kWhPerMonth.size() + 1; i++)
        std::cout << kWhPerMonth[i] << '\n';
    std::cin.get();

}