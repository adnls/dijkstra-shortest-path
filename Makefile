all: main.o
	cc main.o dijkstra.o interface.o initialisation.o -o Programme

main.o: main.c initialisation.o interface.o dijkstra.o structures.h dijkstra.h interface.h initialisation.h
	cc -c main.c -o main.o

dijkstra.o: dijkstra.c dijkstra.h initialisation.o structures.h interface.h initialisation.h 
	cc -c dijkstra.c -o dijkstra.o

interface.o: interface.c interface.h initialisation.o structures.h initialisation.h
	cc -c interface.c -o interface.o

initialisation.o: initialisation.c initialisation.h structures.h
	cc -c initialisation.c -o initialisation.o
