all:
	gcc src/strings.c src/main.c -o strings

clean:
	rm -rf strings

test:
	ceedling test:all

test_clean:
	ceedling clean

.PHONY: all clean test test_clean