CFLAGS+=-std=c89

.PHONY: all
all: ex_01 ex_02 ex_06_getop ex_07 sort

objects = alloc.o qsort.o
$(objects): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

ch01 = getline.o
$(addprefix ../ch01/, $(ch01)):
	$(MAKE) -C ../ch01 $@

ch04 = getch.o stack.o polish_calculator.o
$(addprefix ../ch04/, $(ch04)):
	$(MAKE) -C ../ch04 $@

ex_01: ex_01.c ../ch04/getch.o
	$(CC) $(CFLAGS) -o $@ $^

ex_02: ex_02.c ../ch04/getch.o
	$(CC) $(CFLAGS) -o $@ $^

ex_06_getop: ex_06_getop.c ../ch04/getch.o ../ch04/stack.o ../ch04/polish_calculator.o
	$(CC) $(CFLAGS) -o $@ $^

sort: sort.c qsort.o alloc.o ../ch01/getline.o
	$(CC) $(CFLAGS) -o $@ $^


ex_07: ex_07.c qsort.o alloc.o ../ch01/getline.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(objects) $(all)
