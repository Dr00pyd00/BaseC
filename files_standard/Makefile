
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o

.PHONY: clean
