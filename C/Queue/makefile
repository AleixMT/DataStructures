CC = gcc
CFLAGS = -O3 -Wall

all : main

main : main.c pilas.c colas.c
	$(CC) $(CFLAGS) main.c pilas.c colas.c -o main -lm

run : main
	./main

.PHONY : clean
clean :
	rm -f main

