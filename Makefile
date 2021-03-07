automat:
	gcc -Wall *.c -o automat

actualize.o: actualize.h matrix-io.h

matrix-io.o: matrix-io.h


test_1: automat
	./automat test
