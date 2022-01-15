#include <iostream>

bool exit = false;
double latitude = 51.688307;
double langitude = 5.286983;
int slope = 40;
int orientation = -45;
int power = 350;
int energyUsage = 4000;

int main(){
    while(!exit)
    
    //enable when input
    std::cout << "Enter Latitude (decimal degrees):" << std::endl;
    std::cin >> latitude;
    std::cout << "Enter langitude (decimal degrees):" << std::endl;
    std::cin >> langitude;
    std::cout << "Enter Fixed slope of modules (degrees) (min 0. max 90):" << std::endl;
    std::cin >> slope;
    std::cout << "Enter Orientation (azimuth) of modules (degrees) (min -180. max 180.):" << std::endl;
    std::cin >> orientation;
    std::cout << "Enter Nominal power of the PV system (c-Si) (kWp) (min 0. max 500.): " << std::endl;
    std::cin >> power;
    std::cout << "Enter energy usage (kWh/year) (min 0. max 20000.)" << std::endl;
    std::cin >> energyUsage;
}   