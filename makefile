CC=gcc
CFLAGS= -g -Wall
TARGET=main

all:
	$(CC) $(CFLAGS) sonarSweep.c -o $(TARGET)

sonar-sweep:
	$(CC) $(CFLAGS) sonarSweep.c -o $(TARGET)

dive:
	$(CC) $(CFLAGS) dive.c -o $(TARGET)

clean: 
	rm $(TARGET)
