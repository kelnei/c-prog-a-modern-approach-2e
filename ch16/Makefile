CFLAGS = -O -Wall -W -pedantic -ansi -std=c99

all: inventory pp1 pp5 pp6

inventory:  inventory.o readline.o
	cc $(CFLAGS) -o inventory inventory.o readline.o

inventory.o: inventory.c readline.h
	cc $(CFLAGS) -c -o inventory.o inventory.c

readline.o: readline.c readline.h
	cc $(CFLAGS) -c -o readline.o readline.c

clean:
	rm -f *.o inventory pp1 pp5 pp6
