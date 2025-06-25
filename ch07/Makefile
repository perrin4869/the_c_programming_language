CFLAGS+=-std=c89
ifeq ($(DEBUG), 1)
	CFLAGS+=-DDEBUG
endif

.PHONY: all
all: upper lower ex_02 ex_02_answkerskey ex_03 ex_03_answerskey ex_04 ex_04_answerskey ex_05 ex_05_answerskey ex_05_answerskey2

ch04 = stack.o polish_calculator.o
$(addprefix ../ch04/, $(ch04)):
	$(MAKE) -C ../ch04 $(notdir $@)

upper: ex_01.c
	$(CC) $(CFLAGS) -o $@ $^

lower: ex_01.c
	$(CC) $(CFLAGS) -o $@ $^

ex_02: ex_02.c
	$(CC) $(CFLAGS) -o $@ $^

ex_02_answerskey: ex_02_answerskey.c
	$(CC) $(CFLAGS) -o $@ $^

ex_03: ex_03.c
	$(CC) $(CFLAGS) -o $@ $^

ex_03_answerskey: ex_03_answerskey.c
	$(CC) $(CFLAGS) -o $@ $^

ex_04: ex_04.c
	$(CC) $(CFLAGS) -o $@ $^

ex_04_answerskey: ex_04_answerskey.c
	$(CC) $(CFLAGS) -o $@ $^

ex_05: ex_05.c ../ch04/stack.o ../ch04/polish_calculator.o
	$(CC) $(CFLAGS) -o $@ $^

ex_05_answerskey: ex_05_answerskey.c ../ch04/stack.o ../ch04/polish_calculator.o
	$(CC) $(CFLAGS) -o $@ $^

ex_05_answerskey2: ex_05_answerskey2.c ../ch04/stack.o ../ch04/polish_calculator.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(all)

