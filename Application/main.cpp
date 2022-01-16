#include <iostream>
#include <string>

double latitude = 45.000;
double langitude = 8.000;
int peakPower = 1.0;
const int loss = 14;
int angle = 0;
int aspect = 0;
int energyUsage = 4000;

// Check if input corresponds to the type of variable and to check if input is between min and max.
template <typename T>
void checkInput(T variableType, int min, int max){
    while(!(std::cin >> variableType) || !(variableType >= min && variableType <= max)){
        std::cout << "Wrong input. Try again."  << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n') ;
    }
}

int main()  {
    std::cout << "Enter Latitude (degrees):" << std::endl;
    checkInput<double>(latitude, -90, 90);
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