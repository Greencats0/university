AC=nasm
CC=gcc

AFLAGS= -felf64 -g -F dwarf
CFLAGS = -g -no-pie

OBJ = output.o
TARGET= output

%.o: %.asm
	$(AC) -o $@ $< $(AFLAGS)
all: $(OBJ)	
	$(CC) -o $(TARGET) $^ $(CFLAGS)
run: $(TARGET)
	./$(TARGET)
clean: 
	rm $(OBJ) $(TARGET)
.PHONY: all run
