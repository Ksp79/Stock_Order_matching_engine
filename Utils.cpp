#include<iostream>
#include "Order.h"
using namespace std;

void printOrder(const Order& o){
    cout<<"Order ID: "<<o.OrderID<<"\n";

    if(o.side == Side::Buy)
    cout<<"Side: Buy\n";
    else
    cout<<"Side: Sell\n";

    cout<<"Price: "<<o.Price<<"\n";
    cout<<"Quantity: "<<o.Quantity<<"\n";
}