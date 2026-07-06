#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <vector>
#include "Order.h"
using namespace std;

class OrderBook{
    private:
    vector<Order> buyOrders;
    vector<Order> sellOrders;

    public:
    void addOrder(const Order& order);

    void printBook() const;

    //Rather than this we will use the last two
    // These getters expose the internal vectors.
    // We'll eventually stop using them inside MatchingEngine
    // in favor of getSellOrder(), getBuyOrder(), and the count functions.
    const vector<Order>& getBuyOrders() const;
    const vector<Order>& getSellOrders() const;
    // First const: caller cannot modify the returned vector.
    // Second const: this function cannot modify the OrderBook.

    void removeBuyOrder(size_t index); //here we use size_t since vector.size() returns size_t value however int also works
    void removeSellOrder(size_t index);

    //we will use the following functions to get a specific order
    Order& getSellOrder(size_t index); //Give me one specific order that I can modify.
    Order& getBuyOrder(size_t index);

    //the following functions to get size of vectors or whatever data structure we use
    size_t getSellOrderCount() const;
    size_t getBuyOrderCount() const;

};

#endif