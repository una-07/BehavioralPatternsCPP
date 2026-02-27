#pragma once
#include "ICostCalculationStrategy.h"

class FlightStrategy : public ICostCalculationStrategy {
public:
    double CalculateCost(const BookingData& data) override {
        double base = data.distance * 0.5;

        if (data.businessClass)
            base *= 1.8;

        base += data.baggageCount * 20;

        if (data.childDiscount)
            base *= 0.8;

        if (data.pensionerDiscount)
            base *= 0.85;

        return base * data.passengers;
    }
};
