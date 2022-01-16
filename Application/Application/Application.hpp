#pragma once

template <typename T>
T Application::checkInput(T variableType, int min, int max) {
    while (!(std::cin >> variableType) || !(variableType >= min && variableType <= max)) {
        if (std::cin.fail()) {
            std::cout << "Wrong input. Please input correct type." << std::endl;
        }
        else {
            std::cout << "Wrong input. Please use a value between " << to_string(min) << " and " << to_string(max) << "." << std::endl;
        }
        std::cin.clear();
        while (std::cin.get() != '\n') {}
    }
    return variableType;
}