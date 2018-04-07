#makefile

default : sb.o
	gcc sb.o -o sb

sb.o : main.c
	gcc -c main.c -o sb.o

clean : 
	rm sb.o
