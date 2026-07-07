CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = main

SRCS = main.cpp Order.cpp OrderBook.cpp MatchingEngine.cpp Utils.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)