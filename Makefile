CXX=g++
CXXFLAGS=-g -lm -Wall
PROJECT=BacteriaModel
OBJECTS=main.o Plot.o Bacteria.o Lineage.o Bacterium.o
HEADERS=globals.h

all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(PROJECT)

main.o: $(HEADERS) main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Plot.o: $(HEADERS) Plot.cpp Plot.h
	$(CXX) $(CXXFLAGS) -c Plot.cpp -o Plot.o

Bacteria.o: $(HEADERS) Bacteria.cpp Bacteria.h
	$(CXX) $(CXXFLAGS) -c Bacteria.cpp -o Bacteria.o

Lineage.o: $(HEADERS) Lineage.cpp Lineage.h 
	$(CXX) $(CXXFLAGS) -c Lineage.cpp -o Lineage.o

Bacterium.o: $(HEADERS) Bacterium.cpp Bacterium.h
	$(CXX) $(CXXFLAGS) -c Bacterium.cpp -o Bacterium.o

clean:
	rm *.o $(PROJECT)
