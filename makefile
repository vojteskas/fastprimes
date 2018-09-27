fastprimes: fastprimes.o
	gcc -Wall -o fastprimes fastprimes.o

fastprimes.o: fastprimes.c linkedlist.h linkedlist.c
	gcc -Wall -Wextra -Werror -c fastprimes.c
