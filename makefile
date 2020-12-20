CC=gcc
CFLAGS=-Wall -g

all: mainapp

mainapp: main.o func.o
	$(CC) $(CFLAGS) main.o func.o -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

func.o: func.c
	$(CC) $(CFLAGS) -c func.c

clean:
	rm main *.o mainapp
