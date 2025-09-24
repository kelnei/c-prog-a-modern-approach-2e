CFLAGS = -g -O -Wall -W -pedantic -ansi -std=c99
SOURCES = $(wildcard *.c)
TARGETS = $(basename $(SOURCES))

all: $(TARGETS)

pp8:  pp8.o readline.o
	cc $(CFLAGS) -o pp8 pp8.o readline.o

pp8.o: pp8.c readline.h
	cc $(CFLAGS) -c -o pp8.o pp8.c

pp10:  pp10.o readline.o
	cc $(CFLAGS) -o pp10 pp10.o readline.o

pp10.o: pp10.c readline.h
	cc $(CFLAGS) -c -o pp10.o pp10.c

.PHONY: readline

readline.o: readline.c readline.h
	cc $(CFLAGS) -c -o readline.o readline.c

clean:
	rm -f $(TARGETS)

