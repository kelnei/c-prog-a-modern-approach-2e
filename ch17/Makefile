CFLAGS = -O -Wall -W -pedantic -ansi -std=c99

all: inventory2 remind2 tabulate pp2 pp3 pp4 pp5 pp6 pp7

inventory2:  inventory2.o readline.o
	cc $(CFLAGS) -o inventory2 inventory2.o readline.o

inventory2.o: inventory2.c readline.h
	cc $(CFLAGS) -c -o inventory2.o inventory2.c

readline.o: readline.c readline.h
	cc $(CFLAGS) -c -o readline.o readline.c

remind2: remind2.c
	
tabulate: tabulate.o
	cc $(CFLAGS) -o tabulate tabulate.o -lm

pp2: pp2.o readline.o
	cc $(CFLAGS) -o pp2 pp2.o readline.o

pp3: pp3.o readline.o
	cc $(CFLAGS) -o pp3 pp3.o readline.o

pp4:  pp4.o word.o line.o
	cc $(CFLAGS) -o pp4 pp4.o word.o line.o

pp4.o: pp4.c word.h line.h
	cc $(CFLAGS) -c -o pp4.o pp4.c

word.o: word.c word.h
	cc $(CFLAGS) -c -o word.o word.c

line.o: line.c line.h
	cc $(CFLAGS) -c -o line.o line.c

pp5: pp5.c

pp6: pp6.c

pp7: pp7.c

clean:
	rm -f *.o inventory2 remind2 tabulate pp2 pp3 pp4 pp5 pp6 pp7
