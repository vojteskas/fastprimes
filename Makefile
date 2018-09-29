fastprimes: fastprimes.o linkedlist.o
	gcc -o $@ $^

%.o: %.c
	gcc -std=c99 -Wall -Wextra -Werror -pedantic -c -o $@ $<
