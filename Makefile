CC = gcc
CFLAGS = -Wall -std=c99 -Iraylib/include -Iinclude
LDFLAGS = raylib/lib/libraylib.a -lm -ldl -lpthread -lGL -lX11

# Append debug flags conditionally
ifeq ($(debug),1)
	CFLAGS += -g -O0
endif

SRC = $(wildcard src/*.c)
OUT = game

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT)
