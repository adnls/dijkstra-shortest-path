all: main.o
	cc main.o dijkstra.o interface.o initialisation.o csv.o -o Programme

main.o: main.c initialisation.o interface.o dijkstra.o structures.h dijkstra.h interface.h initialisation.h
	cc -c main.c -o main.o

dijkstra.o: dijkstra.c dijkstra.h initialisation.o structures.h interface.h initialisation.h 
	cc -c dijkstra.c -o dijkstra.o

interface.o: interface.c interface.h initialisation.o csv.o structures.h initialisation.h csv.h
	cc -c interface.c -o interface.o

initialisation.o: initialisation.c initialisation.h csv.o structures.h csv.h
	cc -c initialisation.c -o initialisation.o

csv.o: csv.c csv.h
	cc -c csv.c -o csv.o

