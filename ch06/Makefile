CFLAGS+=-std=c89
ifeq ($(DEBUG), 1)
	CFLAGS+=-DDEBUG
endif

.PHONY: all
all: ccountwords ex_01 ex_01_answerskey ccountwords2

objects = getword.o strdup.o tnode.o
$(objects): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

ch04 = getch.o
$(addprefix ../ch04/, $(ch04)):
	$(MAKE) -C ../ch04 $(notdir $@)

ccountwords: ccountwords.c getword.o ../ch04/getch.o
	$(CC) $(CFLAGS) $^ -o $@

ex_01: ccountwords.c ex_01.c ../ch04/getch.o
	$(CC) $(CFLAGS) -o $@ $^

ex_01_answerskey: ccountwords.c ex_01_answerskey.c ../ch04/getch.o
	$(CC) $(CFLAGS) -o $@ $^

ccountwords2: ccountwords2.c getword.o ../ch04/getch.o
	$(CC) $(CFLAGS) $^ -o $@

countwords: countwords.c strdup.o tnode.o getword.o ../ch04/getch.o
	$(CC) $(CFLAGS) $^ -o $@

# getword from ex_01.c instead of getword.o
ex_02: ex_02.c ex_01.c strdup.o tnode.o ../ch04/getch.o
	$(CC) $(CFLAGS) -o $@ $^

ex_02_answerskey: ex_02_answerskey.c ex_01.c strdup.o ../ch04/getch.o
	$(CC) $(CFLAGS) -o $@ $^

ex_03: ex_03.c strdup.o ../ch04/getch.o
	$(CC) $(CFLAGS) -o $@ $^

ex_03_answerskey: ex_03_answerskey.c strdup.o ../ch04/getch.o
	$(CC) $(CFLAGS) -o $@ $^

ex_04: ex_04.c strdup.o tnode.o getword.o ../ch04/getch.o
	$(CC) $(CFLAGS) $^ -o $@

ex_04_answerskey: ex_04_answerskey.c strdup.o tnode.o getword.o ../ch04/getch.o
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(objects) $(all)
