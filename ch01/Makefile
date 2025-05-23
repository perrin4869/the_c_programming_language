CFLAGS+=-std=c89

objects = getline.o
$(objects): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

detab: ex_20.c
	$(CC) $(CFLAGS) $< -o detab

entab: ex_21.c
	$(CC) $(CFLAGS) $< -o entab

.PHONY: clean
clean:
	rm -f $(objects)
