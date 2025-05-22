CFLAGS+=-std=c89

objects = getline.o
$(objects): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(objects)
