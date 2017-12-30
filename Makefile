# Makefile for Matrix

CXX = g++
OBJECTS = main.o fraction.o matrix.o

Matrix: $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS)
	
main.o: main.cpp
fraction.o: fraction.hpp fraction.cpp
matrix.o: matrix.hpp matrix.cpp

.PHONY: clean
clean:
	$(RM) Matrix $(OBJECTS)