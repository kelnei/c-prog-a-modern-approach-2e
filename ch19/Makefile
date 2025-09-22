CFLAGS = -O -Wall -W -pedantic -ansi -std=c99

all: stackclient pp1 pp2 pp3 pp4 pp5 pp6 pp7

stackclient:  stackclient.o stackADT3.o
	cc $(CFLAGS) -o stackclient stackclient.o stackADT3.o

stackclient.o: stackclient.c stackADT.h
	cc $(CFLAGS) -c -o stackclient.o stackclient.c

stackADT.o: stackADT.c stackADT.h
	cc $(CFLAGS) -c -o stackADT.o stackADT.c

stackADT2.o: stackADT2.c stackADT2.h
	cc $(CFLAGS) -c -o stackADT2.o stackADT2.c

stackADT3.o: stackADT3.c stackADT.h
	cc $(CFLAGS) -c -o stackADT3.o stackADT3.c

pp1:  pp1.o stackADT3.o
	cc $(CFLAGS) -o pp1 pp1.o stackADT3.o

pp2:  pp2.o stackADT3.o
	cc $(CFLAGS) -o pp2 pp2.o stackADT3.o

pp3:  pp3.o stackADT3.o
	cc $(CFLAGS) -o pp3 pp3.o stackADT3.o

pp4:  pp4.o stackADT3.o
	cc $(CFLAGS) -o pp4 pp4.o stackADT3.o

pp5:  pp5.o queueADT.o
	cc $(CFLAGS) -o pp5 pp5.o queueADT.o

pp5.o: pp5.c queueADT.h
	cc $(CFLAGS) -c -o pp5.o pp5.c

queueADT.o: queueADT.c queueADT.h
	cc $(CFLAGS) -c -o queueADT.o queueADT.c

pp6:  pp6.o queueADT2.o
	cc $(CFLAGS) -o pp6 pp6.o queueADT2.o

pp6.o: pp6.c queueADT2.h
	cc $(CFLAGS) -c -o pp6.o pp6.c

queueADT2.o: queueADT2.c queueADT2.h
	cc $(CFLAGS) -c -o queueADT2.o queueADT2.c

pp7:  pp7.o queueADT3.o
	cc $(CFLAGS) -o pp7 pp7.o queueADT3.o

pp7.o: pp7.c queueADT.h
	cc $(CFLAGS) -c -o pp7.o pp7.c

queueADT3.o: queueADT3.c queueADT.h
	cc $(CFLAGS) -c -o queueADT3.o queueADT3.c

clean:
	rm -f *.o stackclient pp1 pp2 pp3 pp4 pp5 pp6 pp7
