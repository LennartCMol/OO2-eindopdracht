#include "stdafx.h"

/*
 * bron: https://stackoverflow.com/questions/15186110/webclient-in-c
         
   zip:  WinHttpClient_20100921.zip
         https://www.codeproject.com/Articles/66625/A-Fully-Featured-Windows-HTTP-Wrapper-in-C
 */

#include "WinHttpClient.h"

#include <iostream>
#include <string>
#include <codecvt>
#include <locale>

double latitude = 45.000;
double langitude = 8.000;
int peakPower = 1.0;
const int loss = 14;
int angle = 0;
int aspect = 0;
int energyUsage = 4000;

int main()
{
    string parameterString =
        "https://re.jrc.ec.europa.eu/api/PVcalc?"
        "lat=" + to_string(latitude) + "&"
        "lon=" + to_string(langitude) + "&"
        "peakpower=" + to_string(peakPower) + "&"
        "loss=" + to_string(loss) + "&"
        "angle=" + to_string(angle) + "&"
        "aspect=" + to_string(aspect) + "&";

    std::wstring wParameterString = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(parameterString);

    WinHttpClient client(wParameterString);

    client.SendHttpRequest();
    std::wstring httpResponseHeader  = client.GetResponseHeader();
    std::wstring httpResponseContent = client.GetResponseContent();
    std::string  text( httpResponseContent.begin(), httpResponseContent.end() );

    std::cout << text.c_str() << std::endl;

    std::cin.get();

    return 0;
}
