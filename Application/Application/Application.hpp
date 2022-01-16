#pragma once

template <typename T>
T Application::checkInput(T variableType, int min, int max) {
    while (!(std::cin >> variableType) || !(variableType >= min && variableType <= max)) {
        std::cout << "Wrong input. Try again. Use correct type and value between min and max." << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n') {}
    }
    return variableType;
}