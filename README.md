# Stock Order Matching Engine (C++)

## Overview

This project is a simplified stock order matching engine written in C++. It simulates the core functionality of an electronic exchange by matching buy and sell limit orders using **price-time priority**. The project is designed with an object-oriented architecture and supports multiple stock symbols through separate order books.

## Features

- Limit Buy and Sell Orders
- Multi-stock support using `std::map`
- Partial order execution
- Price-Time Priority (FIFO for equal prices)
- Resting order execution price
- Automatic order removal after complete execution
- Sorted order books for efficient best-order lookup
- Modular object-oriented design

## Project Structure

```
.
├── main.cpp
├── Order.h
├── Order.cpp
├── OrderBook.h
├── OrderBook.cpp
├── MatchingEngine.h
├── MatchingEngine.cpp
├── Utils.cpp
├── README.md
└── Makefile
```

## Technologies Used

- C++17
- STL
  - `std::vector`
  - `std::map`
  - References & Const Correctness
- Object-Oriented Programming
- Git & GitHub

## Matching Logic

- Buy orders match the lowest available sell order.
- Sell orders match the highest available buy order.
- Orders may be partially executed.
- Orders with remaining quantity stay in the order book.
- Trades execute at the **resting order's price**.
- Orders at the same price are matched using **First-In-First-Out (FIFO)**.

## Data Structures

- `std::map<std::string, OrderBook>` stores a separate order book for each stock symbol.
- Each `OrderBook` maintains:
  - Buy orders sorted in descending price order.
  - Sell orders sorted in ascending price order.

This allows constant-time access to the best buy and sell orders.

## How to Build

```bash
g++ main.cpp Order.cpp OrderBook.cpp MatchingEngine.cpp Utils.cpp -o main
```

## How to Run

```bash
./main
```

## Example Output

```
===== TRADE EXECUTED =====
Buyer ID: 4
Seller ID: 2
Price: 182
Quantity: 20
```

## Future Improvements

- Market Orders
- Order Cancellation
- Order Modification
- Better order book data structures (`std::multiset`)
- Unit Testing
- Performance Benchmarking
- Thread-safe Matching Engine

## Learning Outcomes

This project helped reinforce:

- Object-Oriented Design
- STL Containers and Algorithms
- Order Matching Algorithms
- Price-Time Priority
- Software Design Principles
- Git and GitHub Workflow