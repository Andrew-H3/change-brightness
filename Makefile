#makefile

default : sb.o
	gcc sb.o -o sb

sb.o : sb.c
	gcc -c sb.c -o sb.o

clean : 
	rm sb.o

install : sb
	cp sb ~/.bin/sb
