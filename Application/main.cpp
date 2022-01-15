#include <iostream>
#include <string>

std::string input;
bool _exit = false;
double latitude = 51.688307;
double langitude = 5.286983;
int slope = 40;
int orientation = -45;
int power = 350;
int energyUsage = 4000;


template <typename T>
void checkInput(std::string input){
    
    T data = std::stod(input);
}

/*template <typename T>
void checkInput(std::string input, T type, int min, int max){
    while(!(inputStream >> type)){
        std::cout << "Wrong input type."  << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n') ;
    }
}*/

int main()  {
    //enable when input
    std::cout << "Enter Latitude (degrees):" << std::endl;
    std::cin >> input;
    checkInput<double>(input);
    std::cout << "Enter langitude (degrees):" << std::endl;
    std::cout << "Enter Fixed slope of modules (degrees) (min 0. max 90):" << std::endl;
    std::cout << "Enter Orientation (azimuth) of modules (degrees) (min -180. max 180.):" << std::endl;
    std::cin >> orientation;
    std::cout << "Enter Nominal power of the PV system (c-Si) (kWp) (min 0. max 500.): " << std::endl;
    std::cin >> power;
    std::cout << "Enter energy usage (kWh/year) (min 0. max 20000.)" << std::endl;
    std::cin >> energyUsage;
}   

