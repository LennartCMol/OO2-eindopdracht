#include "Application.h"

Application::Application()
{
}

Application::~Application()
{
}

void Application::run() {
    UserInput:
    std::cout << "Enter latitude in degrees. (min -90. max 90.):" << std::endl;
    latitude = checkInput<double>(latitude, -90, 90);
    std::cout << "Enter langitude in degrees. (min -180. max 180.):" << std::endl;
    langitude = checkInput<double>(langitude, -180, 180);
    std::cout << "Enter nominal power of the PV system in Wp. (min 0. max 500.): " << std::endl;
    // Divide by 1000 to convert Wp into kWp.
    peakPower = (checkInput<double>(peakPower, 0, 500)/1000);
    std::cout << "Enter fixed slope of PV system in degrees. (min 0. max 90):" << std::endl;
    angle = checkInput<int>(angle, 0, 90);
    std::cout << "Enter orientation (azimuth) of PV system in degrees. 0 = south, 90 = west, -90 = east. (min -180. max 180.):" << std::endl;
    aspect = checkInput<int>(aspect, -180, 180);
    std::cout << "Enter energy usage in kWh per year (min 0. max 20000.)" << std::endl;
    energyUsage = checkInput<int>(energyUsage, 0, 20000);

    Webclient client;

    std::string rawData = client.requestData(latitude, langitude, peakPower, loss, angle, aspect);
    
    // Check if api call gives an error.
    if (rawData.at(0) == '{'){
        std::cout << "\nAn error has occured. Please enter your data again." << std::endl;
        goto UserInput;
    }

    Parser parser;

    kWhPerMonth = parser.parse(rawData);

    Calculator calculator;
    calculator.calculateTotalPanels(kWhPerMonth, energyUsage);


    std::cin.get();

}