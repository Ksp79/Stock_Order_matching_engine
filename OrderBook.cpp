#include <iostream>
#include "OrderBook.h"
using namespace std;

void OrderBook::addOrder(const Order& order){
    if(order.side == Side::Buy)
    buyOrders.push_back(order);
    else
    sellOrders.push_back(order);
}

void OrderBook::printBook() const{

    cout<<"===== BUY ORDERS ====\n";

    for(const Order& order: buyOrders){
        cout<<"ID: "<<order.OrderID
            <<" Price: "<<order.Price
            <<" Quantity: "<<order.Quantity
            <<'\n';
    }

    cout<<"\n==== SELL ORDERS ====\n";

    for(const Order& order: sellOrders){
        cout<<"ID: "<<order.OrderID
            <<" Price: "<<order.Price
            <<" Quantity: "<<order.Quantity
            <<'\n';
    }
}

void OrderBook::removeBuyOrder(size_t index)
{
    buyOrders.erase(buyOrders.begin() + index);
}

void OrderBook::removeSellOrder(size_t index)
{
    sellOrders.erase(sellOrders.begin() + index);
}

Order& OrderBook::getSellOrder(size_t index){
    return sellOrders[index];
}

Order& OrderBook::getBuyOrder(size_t index){
    return buyOrders[index];
}

size_t OrderBook::getSellOrderCount() const
{
    return sellOrders.size();
}

size_t OrderBook::getBuyOrderCount() const
{
    return buyOrders.size();
}