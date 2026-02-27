#pragma once
#include "ISubject.h"
#include <map>
#include <iostream>

class StockExchange : public ISubject {
private:
    std::map<std::string, std::vector<IObserver*>> observers;

public:
    void Attach(IObserver* observer, const std::string& stock) override {
        observers[stock].push_back(observer);
        std::cout << "Observer subscribed to " << stock << std::endl;
    }

    void Detach(IObserver* observer) override {
        for (auto& pair : observers) {
            auto& vec = pair.second;
            vec.erase(std::remove(vec.begin(), vec.end(), observer), vec.end());
        }
    }

    void Notify(const std::string& stock, double price) override {
        for (auto* obs : observers[stock])
            obs->Update(stock, price);
    }

    void ChangePrice(const std::string& stock, double price) {
        std::cout << "\nStock " << stock << " changed to " << price << std::endl;
        Notify(stock, price);
    }
};
