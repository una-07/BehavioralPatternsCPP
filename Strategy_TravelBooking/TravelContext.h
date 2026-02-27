#pragma once
#include <memory>
#include <stdexcept>
#include "ICostCalculationStrategy.h"

class TravelContext {
private:
    std::unique_ptr<ICostCalculationStrategy> strategy;

public:
    void SetStrategy(std::unique_ptr<ICostCalculationStrategy> newStrategy) {
        strategy = std::move(newStrategy);
    }

    double Calculate(const BookingData& data) {
        if (!strategy)
            throw std::runtime_error("Strategy not selected!");

        if (data.distance <= 0 || data.passengers <= 0)
            throw std::invalid_argument("Invalid input data!");

        return strategy->CalculateCost(data);
    }
};
