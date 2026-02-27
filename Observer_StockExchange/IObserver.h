#pragma once
#include <string>

class IObserver {
public:
    virtual void Update(const std::string& stock, double price) = 0;
    virtual ~IObserver() = default;
};
