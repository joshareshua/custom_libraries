CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

all: test_runner

test_runner: simple_test.o MyVector.o
	$(CXX) simple_test.o MyVector.o -o test_runner

simple_test.o: tests/simple_test.cpp include/MyVector.h
	$(CXX) $(CXXFLAGS) -c tests/simple_test.cpp

MyVector.o: src/MyVector.cpp include/MyVector.h
	$(CXX) $(CXXFLAGS) -c src/MyVector.cpp

.PHONY: clean

clean: 
	rm -f *.o test_runner