// Tokenizing a string using stringstream
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
     
    string rawData =    "Latitude (decimal degrees):	45.000"
                        "Longitude (decimal degrees):	8.000"
                        "Radiation database:	PVGIS-SARAH"
                        "Nominal power of the PV system (c-Si) (kWp):	1.0"
                        "System losses(%):	14.0"
                        "Fixed slope of modules (deg.):	0"
                        "Orientation (azimuth) of modules (deg.):	0"
                        ""
                        "Fixed angle"
                        "Month		E_d		E_m		H(i)_d		H(i)_m		SD_m"
                        "1		1.21		37.38		1.54		47.75		4.31"
                        "2		1.88		52.57		2.33		65.3		6.74"
                        "3		3.06		94.91		3.79		117.42		10.93"
                        "4		3.84		115.25		4.85		145.62		14.45"
                        "5		4.64		143.87		6.0		    185.89		11.21"
                        "6		5.1		    152.99		6.72		201.7		10.62"
                        "7		5.3		    164.44		7.08		219.53		9.6"
                        "8		4.53		140.47		6.01		186.24		7.45"
                        "9		3.39		101.67		4.4		    131.98		7.49"
                        "10		2.09		64.8		2.65		82.09		9.86"
                        "11		1.23		36.75		1.59		47.73		6.91"
                        "12		1.04		32.21		1.37		42.34		4.02"
                        "Year   3.12		94.78		4.04		122.8		3.53"
                        "		AOI loss (%)		Spectral effects (%)		Temperature and low irradiance loss (%)         Combined loss (%)"
                        "Fixed angle:		-3.95		0.92		-7.42		-22.82"
                        ""
                        "E_d: Average daily energy production from the given system (kWh/d)"
                        "E_m: Average monthly energy production from the given system (kWh/mo)"
                        "H(i)_d: Average daily sum of global irradiation per square meter received by the modules of the given system (kWh/m2/d)"
                        "H(i)_m: Average monthly sum of global irradiation per square meter received by the modules of the given system (kWh/m2/mo)"
                        "SD_m: Standard deviation of the monthly energy production due to year-to-year variation (kWh)"
                        ""
                        ""
                        "PVGIS (c) European Union, 2001-2021";
     
    // Vector of string to save tokens
    vector <string> tokens;
     
    // stringstream class check1
    stringstream check1(rawData);
     
    string intermediate;
     
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }
     
    // Printing the token vector
    for(int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << '\n';
}