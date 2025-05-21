CFLAGS+=-std=c89

all: ex_01

../ch04/getch.o:
	$(MAKE) -C ../ch04 getch.o
../ch04/stack.o:
	$(MAKE) -C ../ch04 stack.o
../ch04/polish_calculator.o:
	$(MAKE) -C ../ch04 polish_calculator.o

ex_01: ex_01.c ../ch04/getch.o
	$(CC) $(CFLAGS) -o $@ $^

ex_02: ex_02.c ../ch04/getch.o
	$(CC) $(CFLAGS) -o $@ $^

ex_06_getop: ex_06_getop.c ../ch04/getch.o ../ch04/stack.o ../ch04/polish_calculator.o
	$(CC) $(CFLAGS) -o $@ $^
