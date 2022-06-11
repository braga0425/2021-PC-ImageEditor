all: main.o functions.o 
	gcc main.o functions.o -o main
	rm -f *.o

main.o: main.c
	gcc -c main.c

functions.o: functions.c functions.h
	gcc -c -o functions.o functions.c