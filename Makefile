CXX=g++
CXXFLAGS=-g -lm
PROJECT=BacteriaModel

all: main.o Plot.o
	$(CXX) $(CXXFLAGS) main.o Plot.o -o $(PROJECT)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Plot.o: Plot.cpp
	$(CXX) $(CXXFLAGS) -c Plot.cpp -o Plot.o

clean:
	rm *.o $(PROJECT)
