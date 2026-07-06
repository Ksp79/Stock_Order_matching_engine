#include "Order.h"

Order::Order(int id, std::string symbol, Side s, int p, int q){
//here we did Order::Order since we are defining the constructor outside the Order struct
//so we need to define which scope the second Order belongs to
//Which Scope :: What are we defining
//We can also do Order::printOrder where printOrder is a methode declared (but not defined) in struct Order
    OrderID = id;
    Symbol = symbol;
    side = s;
    Price = p;
    Quantity = q;
}