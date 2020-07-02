CC = gcc
CFLAGS = -O3 -Wall

all : manager

test : ../includes/random.c DoubleLinkedList.c DoubleLinkedList_test.c
	$(CC) $(CFLAGS) ../includes/random.c DoubleLinkedList.c DoubleLinkedList_test.c -o test -lm

manager : DoubleLinkedList.c StudentManager.c
	$(CC) $(CFLAGS) DoubleLinkedList.c StudentManager.c -o manager -lm

run : manager
	./manager

.PHONY : clean
clean :
	rm -f test manager
