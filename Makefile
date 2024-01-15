CC := gcc
LD := gcc
CFLAGS := -O2 
LDFLAGS := -lSDL2 -lSDL2_ttf
SRC := src
OBJ := obj
BIN := bin

SRCS := $(wildcard $(SRC)/*.c)
OBJS := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
DEPS := $(patsubst $(SRC)/%.c,$(OBJ)/%.d,$(SRCS))
TARGET := stopwatch

all: dir $(OBJS) build

$(OBJ)/%.o:$(SRC)/%.c
	$(CC) -MMD -c -o $@ $< $(CFLAGS)

build:
	$(LD) $(OBJS) -o $(BIN)/$(TARGET) $(LDFLAGS)

dir:
	mkdir -p $(BIN) $(OBJ)

run:
	./$(BIN)/$(TARGET)

.PHONY: clean 
clean:
	rm -r $(BIN)/$(TARGET) $(OBJS) $(DEPS)

