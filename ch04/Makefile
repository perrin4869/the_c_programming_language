CFLAGS+=-std=c89

objects = stack.o getop.o getch.o polish_calculator.o
shared_objects = $(objects:.o=.so)

all: calc_static calc_dynamic ex_03 ex_04 ex_05 ex_06 ex_07 ex_08 ex_10 ex_11

ch01 = getline.o
$(addprefix ../ch01/, $(ch01)):
	$(MAKE) -C ../ch01 $(notdir $@)

$(objects): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

calc_static: $(objects)
	$(CC) $(CFLAGS) -o $@ polish_calculator.c $(objects)

$(shared_objects): %.so: %.c
	$(CC) $(CFLAGS) -shared -fPIC $(CFLAGS) $< -o $@

calc_dynamic: $(shared_objects)
	$(CC) $(CFLAGS) -o $@ polish_calculator.c $(addprefix $(shell pwd)/, $(shared_objects))

ex_03: ex_03.c stack.o getch.o
	$(CC) $(CFLAGS) -o $@ $^
ex_04: ex_04.c getop.o getch.o
	$(CC) $(CFLAGS) -o $@ $^
ex_05: ex_05.c stack.o getch.o
	$(CC) $(CFLAGS) -lm -o $@ $^
ex_06: ex_06.c stack.o getch.o
	$(CC) $(CFLAGS) -o $@ $^
ex_07: ex_07.c getch.o
	$(CC) $(CFLAGS) -o $@ $^
ungets.o: ex_07.c
	$(CC) -c $(CFLAGS) -o $@ $^
	objcopy --strip-symbol=main $@
ex_08: ex_08.c polish_calculator.c stack.o getop.o
	$(CC) $(CFLAGS) -o $@ $^
ex_10: ex_10.c polish_calculator.c stack.o ../ch01/getline.o
	$(CC) $(CFLAGS) -o $@ $^
ex_11: ex_11.c polish_calculator.c stack.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(objects) $(shared_objects) $(all)
