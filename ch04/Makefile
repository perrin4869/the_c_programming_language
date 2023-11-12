objects = push_pop.o getop.o getch.o
shared_objects = $(objects:.o=.so)

all: static dynamic

$(objects): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: static
static: $(objects)
	$(CC) -o calc_static polish_calculator.c $(objects)

$(shared_objects): %.so: %.c
	$(CC) -shared -fPIC $(CFLAGS) $< -o $@

dynamic: $(shared_objects)
	$(CC) -o calc_dynamic polish_calculator.c $(addprefix $(shell pwd)/, $(shared_objects))

.PHONY: clean
clean:
	rm -f $(objects) $(shared_objects) calc_static calc_dynamic
