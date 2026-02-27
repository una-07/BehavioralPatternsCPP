#pragma once
#include "ICostCalculationStrategy.h"

class BusStrategy : public ICostCalculationStrategy {
public:
    double CalculateCost(const BookingData& data) override {
        double base = data.distance * 0.2;

        if (data.childDiscount)
            base *= 0.7;

        if (data.pensionerDiscount)
            base *= 0.75;

        return base * data.passengers;
    }
};
