CC = gcc
CFLAGS = -O3 -Wall

all : rpn test

test : pila.c test_pila.c
	$(CC) $(CFLAGS) pila.c test_pila.c -o test

runtest : test
	./test

rpn : pila.c rpn.c
	$(CC) $(CFLAGS) pila.c rpn.c -o rpn

runrpn : rpn
	./rpn

testreals : pila_reals.c test_pila_reals.c
	$(CC) $(CFLAGS) pila_reals.c test_pila_reals.c -o testreals

runtestreals : testreals
	./testreals

rpnreals : pila_reals.c rpn_reals.c
	$(CC) $(CFLAGS) pila_reals.c rpn_reals.c -o rpnreals -lm

runrpnreals : rpnreals
	./rpnreals

.PHONY : clean
clean :
	rm -f test rpn rpnreals testreals
