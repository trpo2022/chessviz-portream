CC=gcc
TARGET=main.o
all:
	$(CC) chess.c -Wall -Werror -o $(TARGET)
clean:
	rm $(TARGET)
