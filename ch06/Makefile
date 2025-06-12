CFLAGS+=-std=c89
ifeq ($(DEBUG), 1)
	CFLAGS+=-DDEBUG
endif

.PHONY: all
all: wordcount ex_01 ex_01_answerskey wordcount2

objects = getword.o
$(objects): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

ch04 = getch.o
$(addprefix ../ch04/, $(ch04)):
	$(MAKE) -C ../ch04 $(notdir $@)

wordcount: wordcount.c getword.o ../ch04/getch.o
	$(CC) $(CFLAGS) $^ -o $@

ex_01: wordcount.c ex_01.c ../ch04/getch.o
	$(CC) $(CFLAGS) -o $@ $^

ex_01_answerskey: wordcount.c ex_01_answerskey.c ../ch04/getch.o
	$(CC) $(CFLAGS) -o $@ $^

wordcount2: wordcount2.c getword.o ../ch04/getch.o
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(objects) $(all)
