project: medical.o
	cc medical.o -o project
main.o: medical.c
	cc -Wall -c medical.c
