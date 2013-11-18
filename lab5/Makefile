all: lab5

lab5: stlist.o lab5.o
	gcc -Wall stlist.o lab5.o -o lab5

lab5.o: lab5.c stlist.h
	gcc -Wall -c lab5.c -o lab5.o

stlist.o: stlist.c stlist.h
	gcc -Wall -c stlist.c -o stlist.o


