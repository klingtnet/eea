CFLAGS  := -Wall -std=c11
CFILES  := eea.c main.c
OBJECTS := $(patsubst %.c,%.o,$(CFILES))

all: main

main: $(OBJECTS)
	gcc $(CFLAGS) -o main $(OBJECTS)

clean:
	rm *.o main
