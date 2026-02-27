#include <iostream>
#include "TravelContext.h"
#include "FlightStrategy.h"
#include "TrainStrategy.h"
#include "BusStrategy.h"

int main() {
    TravelContext context;
    BookingData data;

    std::cout << "Distance: ";
    std::cin >> data.distance;

    std::cout << "Passengers: ";
    std::cin >> data.passengers;

    int transport;
    std::cout << "1-Flight 2-Train 3-Bus: ";
    std::cin >> transport;

    if (transport == 1)
        context.SetStrategy(std::make_unique<FlightStrategy>());
    else if (transport == 2)
        context.SetStrategy(std::make_unique<TrainStrategy>());
    else
        context.SetStrategy(std::make_unique<BusStrategy>());

    data.businessClass = false;
    data.childDiscount = false;
    data.pensionerDiscount = false;
    data.baggageCount = 1;

    try {
        double price = context.Calculate(data);
        std::cout << "Total price: " << price << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << ex.what();
    }

    return 0;
}
