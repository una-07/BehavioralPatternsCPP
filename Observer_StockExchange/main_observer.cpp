#include "StockExchange.h"
#include "Trader.h"
#include "TradingRobot.h"

int main() {
    StockExchange exchange;

    Trader trader1;
    TradingRobot robot(100);

    exchange.Attach(&trader1, "AAPL");
    exchange.Attach(&robot, "AAPL");

    exchange.ChangePrice("AAPL", 120);
    exchange.ChangePrice("AAPL", 90);

    return 0;
}
