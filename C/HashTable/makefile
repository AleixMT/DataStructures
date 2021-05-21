CC = gcc
CFLAGS = -O3 -Wall

all : main

main : main.c thash.c
	$(CC) $(CFLAGS) main.c thash.c -o main -lm

run : main
	./main

.PHONY : clean
clean :
	rm -f main

