#pragma once
#include "IObserver.h"
#include <vector>
#include <algorithm>

class ISubject {
public:
    virtual void Attach(IObserver* observer, const std::string& stock) = 0;
    virtual void Detach(IObserver* observer) = 0;
    virtual void Notify(const std::string& stock, double price) = 0;
    virtual ~ISubject() = default;
};
