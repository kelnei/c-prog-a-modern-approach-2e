CFLAGS = -O -Wall -W -pedantic -ansi -std=c99

all: justify qsort remind pp5

justify:  justify.o word.o line.o
	cc $(CFLAGS) -o justify justify.o word.o line.o

justify.o: justify.c word.h line.h
	cc $(CFLAGS) -c -o justify.o justify.c

word.o: word.c word.h
	cc $(CFLAGS) -c -o word.o word.c

line.o: line.c line.h
	cc $(CFLAGS) -c -o line.o line.c

qsort:  qsort.o quicksort.o
	cc $(CFLAGS) -o qsort qsort.o quicksort.o

qsort.o: qsort.c quicksort.h
	cc $(CFLAGS) -c -o qsort.o qsort.c

quicksort.o: quicksort.c quicksort.h
	cc $(CFLAGS) -c -o quicksort.o quicksort.c

remind:  remind.o readline.o
	cc $(CFLAGS) -o remind remind.o readline.o

remind.o: remind.c readline.h
	cc $(CFLAGS) -c -o remind.o remind.c

readline.o: readline.c readline.h
	cc $(CFLAGS) -c -o readline.o readline.c

pp5:  pp5.o stack.o
	cc $(CFLAGS) -o pp5 pp5.o stack.o

pp5.o: pp5.c stack.h
	cc $(CFLAGS) -c -o pp5.o pp5.c

stack.o: stack.c stack.h
	cc $(CFLAGS) -c -o stack.o stack.c

clean:
	rm -f *.o justify qsort remind pp5
