#include "Webclient.h"

Webclient::Webclient()
{

}

Webclient::~Webclient()
{
}

std::string Webclient::requestData(double latitude, double langitude, int peakPower, const int loss, int angle, int aspect) {
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
    std::wstring httpResponseHeader = client.GetResponseHeader();
    std::wstring httpResponseContent = client.GetResponseContent();
    std::string  text(httpResponseContent.begin(), httpResponseContent.end());

    return text.c_str();
}