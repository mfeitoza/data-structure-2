CPP = g++

main: main.o list.o library.o
	$(CPP) -o main.o list.o library.o main.cpp

list: list.o
	$(CPP) -o -c list.o list.cpp

library: library.o
	$(CPP) -o -c library.o library.cpp
