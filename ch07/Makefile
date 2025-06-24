CFLAGS+=-std=c89
ifeq ($(DEBUG), 1)
	CFLAGS+=-DDEBUG
endif

.PHONY: all
all: upper lower ex_02 ex_02_answkerskey

upper: ex_01.c
	$(CC) $(CFLAGS) -o $@ $^

lower: ex_01.c
	$(CC) $(CFLAGS) -o $@ $^

ex_02: ex_02.c
	$(CC) $(CFLAGS) -o $@ $^

ex_02_answerskey: ex_02_answerskey.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(all)

