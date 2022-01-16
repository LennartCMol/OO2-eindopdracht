// Tokenizing a string using stringstream
#include <bits/stdc++.h>
#include <stdio.h> 
 
using namespace std;
 
int main()
{
     
    string rawData =    "Latitude (decimal degrees):	45.000\n"
                        "Longitude (decimal degrees):	8.000\n"
                        "Radiation database:	PVGIS-SARAH\n"
                        "Nominal power of the PV system (c-Si) (kWp):	1.0\n"
                        "System losses(%):	14.0\n"
                        "Fixed slope of modules (deg.):	0\n"
                        "Orientation (azimuth) of modules (deg.):	0\n"
                        "\n"
                        "Fixed angle\n"
                        "Month		E_d		E_m		H(i)_d		H(i)_m		SD_m\n"
                        "1		1.21		37.38		1.54		47.75		4.31\n"
                        "2		1.88		52.57		2.33		65.3		6.74\n"
                        "3		3.06		94.91		3.79		117.42		10.93\n"
                        "4		3.84		115.25		4.85		145.62		14.45\n"
                        "5		4.64		143.87		6.0		    185.89		11.21\n"
                        "6		5.1		    152.99		6.72		201.7		10.62\n"
                        "7		5.3		    164.44		7.08		219.53		9.6\n"
                        "8		4.53		140.47		6.01		186.24		7.45\n"
                        "9		3.39		101.67		4.4		    131.98		7.49\n"
                        "10		2.09		64.8		2.65		82.09		9.86\n"
                        "11		1.23		36.75		1.59		47.73		6.91\n"
                        "12		1.04		32.21		1.37		42.34		4.02\n"
                        "Year   3.12		94.78		4.04		122.8		3.53\n"
                        "		AOI loss (%)		Spectral effects (%)		Temperature and low irradiance loss (%)         Combined loss (%)\n"
                        "Fixed angle:		-3.95		0.92		-7.42		-22.82\n"
                        "\n"
                        "E_d: Average daily energy production from the given system (kWh/d)\n"
                        "E_m: Average monthly energy production from the given system (kWh/mo)\n"
                        "H(i)_d: Average daily sum of global irradiation per square meter received by the modules of the given system (kWh/m2/d)\n"
                        "H(i)_m: Average monthly sum of global irradiation per square meter received by the modules of the given system (kWh/m2/mo)\n"
                        "SD_m: Standard deviation of the monthly energy production due to year-to-year variation (kWh)\n"
                        "\n"
                        "\n"
                        "PVGIS (c) European Union, 2001-2021\n";
     
    // Vector of string to save tokens
    vector <string> tokens;
     
    // stringstream class check1
    stringstream check1(rawData);
     
    string intermediate;
     
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, '\n'))
    {
        tokens.push_back(intermediate);
    }

    // Vector of string to save useful data
    vector <string> data;

    // Filter rawData by checking for a number(month) at the beginnen of string.
    for (string line : tokens){
        if(line.empty()){
        }
        else if(isdigit(line.at(0))){
            data.push_back(line);
        } 
    }

    // temp string array
    vector <string> temp;

    // Map containing the month mapped to the power
    map<int, double> kWhPerMonth;

    // split data lines and put values of month and E_m into map.
    for (string line : data){
        std::stringstream ss(line);
        for (string i; ss >> i;) {
            temp.push_back(i);    
            if (ss.peek() == '\t'){
                ss.ignore();
            }
        } 
        // Convert string to int and double and put them into the map
        kWhPerMonth.insert(pair<int, double>(stoi(temp[0]), stod(temp[2])));
        temp.clear();
    }

    // Printing map. Month begins at 1.
    for(int i = 1; i < kWhPerMonth.size() + 1; i++)
        cout << kWhPerMonth[i] << '\n';
}