#ifndef ORDER_H //check if ORDER_H is defined already or not
//if already defined don't read the code and proceed till end if
//if not defined proceed with the code
//helpful when we include order.h twice in code filess so it doesn't give redeclaration error

#define ORDER_H //actually defining order_h
#include <string>

enum class Side{
    Buy,
    Sell
};

struct Order{
    int OrderID; //every order has a unique id
    std::string Symbol;
    Side side; // we need to know if the order is to buy or sell
    int Price;
    int Quantity; //remaining quantity to be traded

    Order(int id, std::string symbol, Side s, int p, int q);
};

#endif //ending the if in line 1