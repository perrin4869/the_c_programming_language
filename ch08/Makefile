CFLAGS+=-std=c89
ifeq ($(DEBUG), 1)
	CFLAGS+=-DDEBUG
endif

.PHONY: all
all: itoo cp cat cat_answerskey test_fopen ex_02 ex_02_answerskey

ch07 = cat
$(addprefix ../ch07/, $(ch07)):
	$(MAKE) -C ../ch07 $(notdir $@)

objects = error.o get.o fopen.o
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
	head -c 1M </dev/urandom > input.txt

.PHONY: bench-cat
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

test_fopen: test_fopen.c fopen.o
	$(CC) $(CFLAGS) -o $@ $^

ex_02: test_fopen.c ex_02.c
	$(CC) $(CFLAGS) -o $@ $^

ex_02_answerskey: test_fopen.c ex_02_answerskey.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: bench-fopen
bench-fopen: test_fopen ex_02 ex_02_answerskey input.txt
	@echo "Benchmarking ./test_fopen 1000 times..."
	@/usr/bin/time -f "⏱️  Elapsed time: %e seconds" bash -c '\
	  for i in {1..1000}; do \
	    ./test_fopen > /dev/null; \
	  done'
	@echo "Benchmarking answerskey ./ex_02 1000 times..."
	@/usr/bin/time -f "⏱️  Elapsed time: %e seconds" bash -c '\
	  for i in {1..1000}; do \
	    ./ex_02 > /dev/null; \
	  done'
	@echo "Benchmarking standard library cat ../ch07/cat 1000 times..."
	@/usr/bin/time -f "⏱️  Elapsed time: %e seconds" bash -c '\
	  for i in {1..1000}; do \
	    ./ex_02_answerskey > /dev/null; \
	  done'

.PHONY: clean
clean:
	rm -f $(all) $(objects) foo bar input.txt
