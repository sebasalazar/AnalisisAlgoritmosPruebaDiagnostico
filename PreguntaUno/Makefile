CXX = g++
CXXFLAGS = -g3 -Wall -lm
MKDIR = mkdir -p

LIBS = -lm

directorios:
	$(MKDIR) build dist

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

Circunferencia.o: directorios Circunferencia.cpp Circunferencia.h
	$(CXX) $(CXXFLAGS) -c Circunferencia.cpp -o build/Circunferencia.o

all: clean main.o Circunferencia.o
	$(CXX) $(CXXFLAGS) $(LIBS) -o dist/programa build/main.o build/Circunferencia.o
	rm -fr build

clean:
	rm -fr *.o a.out core programa dist build

.DEFAULT_GOAL := all