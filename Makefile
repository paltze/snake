CC = gcc
CFLAGS = -Wall -std=c99 -Iinclude -Iraylib/include
LDFLAGS = raylib/lib/libraylib.a -lm -ldl -lpthread -lGL -lX11

ifeq ($(debug),1)
	CFLAGS += -g -O0
endif

SRC := $(shell find src -name "*.c")
OUT = game

INCLUDE_DIRS := $(shell find include -type d)
CFLAGS += $(addprefix -I, $(INCLUDE_DIRS))

ifeq ($(rebuild),1)
all:
	@echo "==> Cleaning previous build..."
	$(MAKE) clean
	@echo "==> Regenerating compile_commands.json with bear..."
	bear -- $(MAKE) no-bear
else
all: no-bear
endif

no-bear:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT)
