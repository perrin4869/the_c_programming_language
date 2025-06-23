CFLAGS+=-std=c89
ifeq ($(DEBUG), 1)
	CFLAGS+=-DDEBUG
endif

.PHONY: all
all: upper lower

upper: ex_01.c
	$(CC) $(CFLAGS) -o $@ $^

lower: ex_01.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(all)

