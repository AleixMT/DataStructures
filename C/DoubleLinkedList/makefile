CC = gcc
CFLAGS = -O3 -Wall

all : listtest

listtest : random.c llista.c test_llista.c
	$(CC) $(CFLAGS) random.c llista.c test_llista.c -o listtest -lm

runlisttest : listtest
	./listtest

.PHONY : clean
clean :
	rm -f listtest skiplisttest
