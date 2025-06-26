CFLAGS+=-std=c89
ifeq ($(DEBUG), 1)
	CFLAGS+=-DDEBUG
endif

.PHONY: all
all: upper lower ex_02 ex_02_answkerskey ex_03 ex_03_answerskey ex_04 ex_04_answerskey ex_05 ex_05_answerskey ex_05_answerskey2 ex_06 ex_06_answerskey ex_07 ex_07_answerskey

ch04 = stack.o polish_calculator.o
$(addprefix ../ch04/, $(ch04)):
	$(MAKE) -C ../ch04 $(notdir $@)

upper: ex_01.c
	$(CC) $(CFLAGS) -o $@ $^

lower: ex_01.c
	$(CC) $(CFLAGS) -o $@ $^

ex_02: ex_02.c
	$(CC) $(CFLAGS) -o $@ $^

ex_02_answerskey: ex_02_answerskey.c
	$(CC) $(CFLAGS) -o $@ $^

ex_03: ex_03.c
	$(CC) $(CFLAGS) -o $@ $^

ex_03_answerskey: ex_03_answerskey.c
	$(CC) $(CFLAGS) -o $@ $^

ex_04: ex_04.c
	$(CC) $(CFLAGS) -o $@ $^

ex_04_answerskey: ex_04_answerskey.c
	$(CC) $(CFLAGS) -o $@ $^

ex_05: ex_05.c ../ch04/stack.o ../ch04/polish_calculator.o
	$(CC) $(CFLAGS) -o $@ $^

ex_05_answerskey: ex_05_answerskey.c ../ch04/stack.o ../ch04/polish_calculator.o
	$(CC) $(CFLAGS) -o $@ $^

ex_05_answerskey2: ex_05_answerskey2.c ../ch04/stack.o ../ch04/polish_calculator.o
	$(CC) $(CFLAGS) -o $@ $^

ex_06: ex_06.c
	$(CC) $(CFLAGS) -o $@ $^

ex_06_answerskey: ex_06_answerskey.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: test_06
test_06: ex_06 foo bar baz
	@actual_output="$$(./ex_06 foo bar)"; \
	expected_output="the files differ on line 3"; \
	if [ "$$actual_output" = "$$expected_output" ]; then \
		echo "✅ Output matches expected."; \
	else \
		echo "❌ Output mismatch!"; \
		echo "Actual:   $$actual_output"; \
		echo "Expected: $$expected_output"; \
		exit 1; \
	fi
	@actual_output="$$(./ex_06 foo baz)"; \
	expected_output="the files are equal"; \
	if [ "$$actual_output" = "$$expected_output" ]; then \
		echo "✅ Output matches expected."; \
	else \
		echo "❌ Output mismatch!"; \
		echo "Actual:   $$actual_output"; \
		echo "Expected: $$expected_output"; \
		exit 1; \
	fi

.PHONY: test_06_answerskey
test_06_answerskey: ex_06_answerskey foo bar baz
	@actual_output="$$(./ex_06_answerskey foo bar)"; \
	expected_output="$$(printf 'first difference in line\nccc')"; \
	if [ "$$actual_output" = "$$expected_output" ]; then \
		echo "✅ Output matches expected."; \
	else \
		echo "❌ Output mismatch!"; \
		echo "Actual:   $$actual_output"; \
		echo "Expected: $$expected_output"; \
		exit 1; \
	fi
	@actual_output="$$(./ex_06_answerskey foo baz)"; \
	expected_output=""; \
	if [ "$$actual_output" = "$$expected_output" ]; then \
		echo "✅ Output matches expected."; \
	else \
		echo "❌ Output mismatch!"; \
		echo "Actual:   $$actual_output"; \
		echo "Expected: $$expected_output"; \
		exit 1; \
	fi

ex_07: ex_07.c
	$(CC) $(CFLAGS) -o $@ $^

ex_07_answerskey: ex_07_answerskey.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: test_07
test_07: ex_07 foo bar
	@actual_output="$$(./ex_07 aaa foo bar)"; \
	expected_output="$$(printf 'foo: aaa\nbar: aaa')"; \
	if [ "$$actual_output" = "$$expected_output" ]; then \
		echo "✅ Output matches expected."; \
	else \
		echo "❌ Output mismatch!"; \
		echo "Actual:   $$actual_output"; \
		echo "Expected: $$expected_output"; \
		exit 1; \
	fi
	@actual_output="$$(./ex_07 ccc foo bar)"; \
	expected_output="foo: ccc"; \
	if [ "$$actual_output" = "$$expected_output" ]; then \
		echo "✅ Output matches expected."; \
	else \
		echo "❌ Output mismatch!"; \
		echo "Actual:   $$actual_output"; \
		echo "Expected: $$expected_output"; \
		exit 1; \
	fi

.PHONY: test_07_answerskey
test_07_answerskey: ex_07_answerskey foo bar
	@actual_output="$$(./ex_07_answerskey aaa foo bar)"; \
	expected_output="$$(printf 'foo - aaa\nbar - aaa')"; \
	if [ "$$actual_output" = "$$expected_output" ]; then \
		echo "✅ Output matches expected."; \
	else \
		echo "❌ Output mismatch!"; \
		echo "Actual:   $$actual_output"; \
		echo "Expected: $$expected_output"; \
		exit 1; \
	fi
	@actual_output="$$(./ex_07_answerskey ccc foo bar)"; \
	expected_output="foo - ccc"; \
	if [ "$$actual_output" = "$$expected_output" ]; then \
		echo "✅ Output matches expected."; \
	else \
		echo "❌ Output mismatch!"; \
		echo "Actual:   $$actual_output"; \
		echo "Expected: $$expected_output"; \
		exit 1; \
	fi

.PHONY: clean
clean:
	rm -f $(all)

