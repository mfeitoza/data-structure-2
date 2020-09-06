CPP = g++
LDFLAGS_LINUX = -lncurses

main: main.o list.o
	$(CPP) -o main.o list.o main.cpp ${LDFLAGS_LINUX}
	
list: list.o
	$(CPP) -o -c list.o list.cpp