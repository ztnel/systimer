CC=gcc
CFLAGS=-g -W -Wall -std=c99

systime: systimer.o
	$(CC) -o systimer systimer.o


clean:
	rm -f ./*.o ./systimer