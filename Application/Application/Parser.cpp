#include "Parser.h"

Parser::Parser()
{
}

Parser::~Parser()
{
}

std::map<int, double> Parser::Parse(std::string rawData) {
    // Vector of string to save tokens
    std::vector <std::string> tokens;

    // stringstream class check1
    std::stringstream check1(rawData);

    std::string intermediate;

    // Tokenizing w.r.t. space ' '
    while (std::getline(check1, intermediate, '\n'))
    {
        tokens.push_back(intermediate);
    }

    // Vector of string to save useful data
    std::vector <std::string> data;

    // Filter rawData by checking for a number(month) at the beginnen of string.
    for (std::string line : tokens) {
        if (line.empty()) {
        }
        else if (isdigit(line.at(0))) {
            data.push_back(line);
        }
    }

    // temp string array
    std::vector <std::string> temp;

    // Map containing the month mapped to the power
    std::map<int, double> kWhPerMonth;

    // split data lines and put values of month and E_m into map.
    for (std::string line : data) {
        std::stringstream ss(line);
        for (std::string i; ss >> i;) {
            temp.push_back(i);
            if (ss.peek() == '\t') {
                ss.ignore();
            }
        }
        // Convert string to int and double and put them into the map
        kWhPerMonth.insert(std::pair<int, double>(stoi(temp[0]), stod(temp[2])));
        temp.clear();
    }

    return kWhPerMonth;
}