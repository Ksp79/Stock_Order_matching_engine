#include <iostream>
#include "MatchingEngine.h"

using namespace std;

int main()
{
    MatchingEngine engine;

    engine.processOrder(Order(1, "AAPL", Side::Buy, 190, 20));
    engine.processOrder(Order(2, "AAPL", Side::Buy, 190, 20));

    // Incoming sell order
    engine.processOrder(Order(3, "AAPL", Side::Sell, 185, 30));

    engine.printBook();

    return 0;
}