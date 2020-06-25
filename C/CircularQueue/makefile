CC = gcc
CFLAGS = -O3 -Wall

all : test trianglePascal

test : cua.c test_cua.c ../Stack/pila.c
	$(CC) $(CFLAGS) ../Stack/pila.c cua.c test_cua.c -o test

runtest : test
	./test

trianglePascal : cua.c ../Stack/pila.c trianglePascal.c
	$(CC) $(CFLAGS) cua.c ../Stack/pila.c trianglePascal.c -o trianglePascal

runtriangle : trianglePascal
	./trianglePascal

.PHONY : clean
clean :
	rm -f test trianglePascal
