#pragma once
#include "ICostCalculationStrategy.h"

class TrainStrategy : public ICostCalculationStrategy {
public:
    double CalculateCost(const BookingData& data) override {
        double base = data.distance * 0.3;

        if (data.businessClass)
            base *= 1.4;

        if (data.childDiscount)
            base *= 0.75;

        if (data.pensionerDiscount)
            base *= 0.8;

        return base * data.passengers;
    }
};
