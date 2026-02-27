#pragma once
#include "IObserver.h"
#include <iostream>

class Trader : public IObserver {
public:
    void Update(const std::string& stock, double price) override {
        std::cout << "Trader notified: " << stock << " = " << price << std::endl;
    }
};
