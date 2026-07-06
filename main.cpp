#include<bits/stdc++.h>
#include "MatchingEngine.h"
using namespace std;

int main(){
    MatchingEngine engine;

    // AAPL Orders
    engine.processOrder(Order(1, "AAPL", Side::Sell, 181, 50));
    engine.processOrder(Order(2, "AAPL", Side::Buy, 185, 20));

    // TSLA Orders
    engine.processOrder(Order(3, "TSLA", Side::Sell, 250, 40));
    engine.processOrder(Order(4, "TSLA", Side::Buy, 255, 10));

    engine.printBook();

    return 0;
}