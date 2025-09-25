CFLAGS = -O -Wall -W -pedantic -ansi -std=c99
SOURCES = $(wildcard *.c)
TARGETS = $(basename $(SOURCES))

all: $(TARGETS)

pp1: pp1.o
	cc $(CFLAGS) -o pp1 pp1.o -lm

pp5: pp5.o
	cc $(CFLAGS) -o pp5 pp5.o -lm


clean:
	rm -f $(TARGETS)

