CXX=g++
CXXFLAGS=-g -lm
PROJECT=BacteriaModel

all: main.o Plot.o Bacteria.o
	$(CXX) $(CXXFLAGS) main.o Plot.o Bacteria.o -o $(PROJECT)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Plot.o: Plot.cpp
	$(CXX) $(CXXFLAGS) -c Plot.cpp -o Plot.o

Bacteria.o: Bacteria.cpp
	$(CXX) $(CXXFLAGS) -c Bacteria.cpp -o Bacteria.o

clean:
	rm *.o $(PROJECT)
