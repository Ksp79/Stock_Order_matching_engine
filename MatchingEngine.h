#ifndef MATCHINGENGINE_H
#define MATCHINGENGINE_H

#include "OrderBook.h"
#include <string>
#include <map>

class MatchingEngine{
    private:
    std::map<std::string, OrderBook> orderBooks;

    int findBestSellOrder(const std::string& symbol, int buyPrice);
    int findBestBuyOrder(const std::string& symbol, int sellPrice);

    void matchBuyOrder(Order& order);
    void matchSellOrder(Order& order);

    public:
    void processOrder(Order order); //here we didnt use const Order& since we'll change the quantity after a buy/sell
    //also, we dont want to change the caller's object so we pass by value
    void printBook() const;
};

#endif