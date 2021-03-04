automat: main.o matrix-io.o actualize.o
	gcc -Wall --pedantic -g -o automat main.o matrix-io.o actualize.o

automat1:
	gcc -Wall --pedantic *.c -o automat1

actualize.o: actualize.h matrix-io.h

matrix-io.o: matrix-io.h

test1: automat
	test file


test_1: 
	./automat1 test file3
