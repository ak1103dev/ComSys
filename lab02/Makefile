CXX = g++
CXXFLAGS = -Wall -g

main: first_counter.cpp first_counter_tb.cpp
	$(CXX) $(CXXFLAGS) -o main first_counter.cpp first_counter_tb.cpp -I/usr/local/systemc-2.3.1/include -L/usr/local/systemc-2.3.1/lib-linux64 -lsystemc -lm
