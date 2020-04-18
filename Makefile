CFLAGS=-lm

test: test.c hashtable.o
	gcc -g $(CFLAGS) -o $@ $^

hashtable.o: hashtable.c hashtable.h
	gcc -g -c $<

run: test
	./test

