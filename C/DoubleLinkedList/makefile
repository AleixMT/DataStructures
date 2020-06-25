CC = gcc
CFLAGS = -O3 -Wall

all : listtest

listtest : ../includes/random.c llista.c test_llista.c
	$(CC) $(CFLAGS) ../includes/random.c llista.c test_llista.c -o listtest -lm

runlisttest : listtest
	./listtest

.PHONY : clean
clean :
	rm -f listtest skiplisttest
