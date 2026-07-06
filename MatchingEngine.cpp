#include<iostream>
#include "MatchingEngine.h"
#include<climits>
using namespace std;

void MatchingEngine::processOrder(Order order){
    if(order.side == Side::Buy){
        matchBuyOrder(order);
    }
    else{
        matchSellOrder(order);
    }

    if(order.Quantity > 0){
        orderBooks[order.Symbol].addOrder(order);
    }
}

void MatchingEngine::printBook() const{
    for(const auto& pair: orderBooks){
        cout<<"\n========"
        <<pair.first
        <<"========\n";

        pair.second.printBook();
    }
}

int MatchingEngine::findBestSellOrder(const std::string& symbol, int buyPrice){
    OrderBook& currentOrderBook = orderBooks[symbol];
    int bestIndex = -1;
    int bestPrice = INT_MAX;
    //const vector<Order>& sellOrders = orderBook.getSellOrders();

    // for(size_t i=0; i<sellOrders.size(); i++){
    //     const Order& currentOrder = sellOrders[i];
    //     if(currentOrder.Price<=buyPrice && currentOrder.Price<bestPrice){
    //         bestPrice = currentOrder.Price;
    //         bestIndex = i;
    //     }
    // }

    for(size_t i=0; i<currentOrderBook.getSellOrderCount(); i++){

        Order& currentOrder = currentOrderBook.getSellOrder(i);

        if(currentOrder.Price <= buyPrice && 
           currentOrder.Price < bestPrice){

            bestPrice = currentOrder.Price;
            bestIndex = i;
        }
    }

    return bestIndex;
}

int MatchingEngine::findBestBuyOrder(const std::string& symbol, int sellPrice){
    OrderBook& currentOrderBook = orderBooks[symbol];
    int bestIndex = -1;
    int bestPrice = INT_MIN;

    for(size_t i=0; i<currentOrderBook.getBuyOrderCount(); i++){

        Order& currentOrder = currentOrderBook.getBuyOrder(i);

        if(currentOrder.Price >= sellPrice && 
           currentOrder.Price > bestPrice){
            
            bestIndex = i;
            bestPrice = currentOrder.Price;
        }
    }

    return bestIndex;
}

void MatchingEngine::matchBuyOrder(Order& order){
    OrderBook& currentOrderBook = orderBooks[order.Symbol];
    while(order.Quantity > 0){
        int bestIndex = findBestSellOrder(order.Symbol, order.Price);

        if(bestIndex == -1){
            break;
        }

        Order& seller = currentOrderBook.getSellOrder(bestIndex);

        int tradeQuantity = min(order.Quantity, seller.Quantity);
        order.Quantity -= tradeQuantity;
        seller.Quantity -= tradeQuantity;

        cout<<"\n===== TRADE EXECUTED =====\n";
        cout<<"Buyer ID: "<<order.OrderID<<'\n';
        cout<<"Seller ID: "<<seller.OrderID<<'\n';
        cout<<"Price: "<<seller.Price<<'\n';
        cout<<"Quantity: "<<tradeQuantity<<"\n\n";

        if(seller.Quantity == 0)
        currentOrderBook.removeSellOrder(bestIndex);
    }
}

void MatchingEngine::matchSellOrder(Order& order){
    OrderBook& currentOrderBook = orderBooks[order.Symbol];
    while(order.Quantity > 0){
        int bestIndex = findBestBuyOrder(order.Symbol, order.Price);

        if(bestIndex == -1){
            break;
        }

        Order& buyer = currentOrderBook.getBuyOrder(bestIndex);

        int tradeQuantity = min(order.Quantity, buyer.Quantity);
        order.Quantity -= tradeQuantity;
        buyer.Quantity -= tradeQuantity;

        cout<<"\n===== TRADE EXECUTED =====\n";
        cout<<"Buyer ID: "<<buyer.OrderID<<'\n';
        cout<<"Seller ID: "<<order.OrderID<<'\n';
        cout<<"Price: "<<order.Price<<'\n';
        cout<<"Quantity: "<<tradeQuantity<<"\n\n";

        if(buyer.Quantity == 0)
        currentOrderBook.removeBuyOrder(bestIndex);
    }
}