#pragma once
#include "IObserver.h"
#include <iostream>

class TradingRobot : public IObserver {
private:
    double threshold;

public:
    TradingRobot(double t) : threshold(t) {}

    void Update(const std::string& stock, double price) override {
        if (price < threshold)
            std::cout << "Robot buying " << stock << std::endl;
        else
            std::cout << "Robot waiting for better price\n";
    }
};
