CC = gcc
CFLAGS = -O3 -Wall

test : ArrayList.o ArrayListTest.o
	$(CC) $(CFLAGS) -o test ArrayList.o ArrayListTest.o -lm

ArrayList.o : ArrayList.c
	gcc -c ArrayList.c

ArrayListTest.o : ArrayListTest.c
	gcc -c ArrayListTest.c

run : test
	./test

.PHONY : clean
clean :
	rm -f test.o test ArrayList.o ArrayListTest.o
