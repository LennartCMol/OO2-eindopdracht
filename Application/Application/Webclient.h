#pragma once

#include "stdafx.h"

#include "WinHttpClient.h"

#include <iostream>
#include <string>
#include <codecvt>
#include <locale>

class Webclient
{
public:
	Webclient();
	~Webclient();
	std::string requestData(double, double, int, const int, int, int);

private:
};

