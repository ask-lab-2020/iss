CC=gcc
OBJS=main.o instruction.o
TARGET=rv32i_iss

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: main.c
instruction.o: instruction.c instruction.h

clean:
	rm -f *.o
	rm -f $(TARGET)
