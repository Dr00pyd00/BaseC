
CC = gcc 
CFLAGS = -Wall -Wextra -pedantic -g 

main: main.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c 
	$(CC) $(CFLAGS) -c $^ -o $@ 

clean:
	rm -f main.o main 

.PHONY: clean
