CFLAGS+=-std=c89
ifeq ($(DEBUG), 1)
	CFLAGS+=-DDEBUG
endif

.PHONY: all
all: ccountwords ex_01 ex_01_answerskey ccountwords2

objects = getword.o tnode.o
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

countwords: countwords.c tnode.o getword.o ../ch04/getch.o
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(objects) $(all)
