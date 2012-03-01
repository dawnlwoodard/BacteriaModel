CXX=g++
CXXFLAGS=-g -lm
PROJECT=BacteriaModel

all: main.o
	$(CXX) $(CXXFLAGS) main.o -o $(PROJECT)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm *.o $(PROJECT)
