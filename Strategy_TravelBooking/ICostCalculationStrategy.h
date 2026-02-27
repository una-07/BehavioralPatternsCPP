#pragma once
#include "BookingData.h"

class ICostCalculationStrategy {
public:
    virtual double CalculateCost(const BookingData& data) = 0;
    virtual ~ICostCalculationStrategy() = default;
};
