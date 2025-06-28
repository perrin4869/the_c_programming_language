CFLAGS+=-std=c89
ifeq ($(DEBUG), 1)
	CFLAGS+=-DDEBUG
endif

.PHONY: all
all: itoo

ch07 = cat
$(addprefix ../ch07/, $(ch07)):
	$(MAKE) -C ../ch07 $(notdir $@)

objects = error.o
$(objects): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# copy input to output
itoo: itoo.c
	$(CC) $(CFLAGS) -o $@ $^

cp: cp.c error.o
	$(CC) $(CFLAGS) -o $@ $^

test-cp: cp
	@echo "Creating input file 'foo'..."
	echo "hello world" > foo
	@echo "Running ./cp foo bar..."
	./cp foo bar
	@echo "Comparing contents of foo and bar..."
	@if cmp -s foo bar; then \
	  echo "✅ Copy successful: foo and bar are identical."; \
	else \
	  echo "❌ Copy failed: foo and bar differ."; \
	  exit 1; \
	fi

cat: ex_01.c
	$(CC) $(CFLAGS) -o $@ $^

cat_answerskey: ex_01_answerskey.c error.o
	$(CC) $(CFLAGS) -o $@ $^

input.txt:
	@echo "Generating input.txt (1MB)..."
	head -c 1k </dev/urandom > input.txt

bench-cat: cat cat_answerskey input.txt ../ch07/cat
	@echo "Benchmarking ./cat 1000 times..."
	@/usr/bin/time -f "⏱️  Elapsed time: %e seconds" bash -c '\
	  for i in {1..1000}; do \
	    ./cat input.txt > /dev/null; \
	  done'
	@echo "Benchmarking answerskey ./cat_answerskey 1000 times..."
	@/usr/bin/time -f "⏱️  Elapsed time: %e seconds" bash -c '\
	  for i in {1..1000}; do \
	    ./cat_answerskey input.txt > /dev/null; \
	  done'
	@echo "Benchmarking standard library cat ../ch07/cat 1000 times..."
	@/usr/bin/time -f "⏱️  Elapsed time: %e seconds" bash -c '\
	  for i in {1..1000}; do \
	    ../ch07/cat input.txt > /dev/null; \
	  done'

.PHONY: clean
clean:
	rm -f $(all) foo bar input.txt
