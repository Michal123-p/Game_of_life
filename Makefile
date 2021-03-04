automat: main.c matrix-io.c
	gcc -Wall -pedantic -g -o automat main.c matrix-io.c

test1: automat 
	test 2
