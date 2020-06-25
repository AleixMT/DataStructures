CC = gcc
CFLAGS = -O3 -Wall

all : skiplisttest

skiplisttest : ../includes/random.c skiplist.c test_skiplist.c
	$(CC) $(CFLAGS) ../includes/random.c skiplist.c test_skiplist.c -o skiplisttest -lm

run : skiplisttest
	./skiplisttest

.PHONY : clean
clean :
	rm -f skiplisttest
