automat:
	gcc -Wall *.c -o automat


actualize.o: actualize.h matrix-action.h

matrix-io.o: matrix-io.h matrix-action.h

matrix-action.o: matrix-action.h



test: automat
	./automat tests/test1

test_1: automat
	./automat tests/test 12

test_1N: automat
	./automat tests/test 12 0


.PHONY: clean

clean: 
	-rm *.o automat