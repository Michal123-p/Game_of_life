automat: main.o matrix-io.o actualize.o
	gcc -Wall --pedantic -g automat main.o matrix-io.o actualize.o

automat1:
	gcc -Wall --pedantic *.c -o

actualize.o: actualize.h matrix-io.h

matrix-io.o: matrix-io.h

test1: automat
	test file


test:
	./test1