CFLAGS = -O -Wall -W -pedantic -ansi -std=c99
SOURCES = $(wildcard *.c)
TARGETS = $(basename $(SOURCES))

all: $(TARGETS)

pp1: pp1.o
	cc $(CFLAGS) -o pp1 pp1.o -lm

pp2: pp2.o
	cc $(CFLAGS) -o pp2 pp2.o -lm

pp3: pp3.o
	cc $(CFLAGS) -o pp3 pp3.o -lm

pp4: pp4.o
	cc $(CFLAGS) -o pp4 pp4.o -lm

clean:
	rm -f *.o $(TARGETS)

