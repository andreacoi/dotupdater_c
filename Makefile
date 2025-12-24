CC = cc
CFLAGS = -Wall -Wextra -g
OBJ = dup.o connect.o
TARGET = dup

$TARGET: $(OBJ)
			$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

dup.o: dup.c connect.h
			$(CC) $(CFLAGS) -c dup.c

connect.o: connect.c connect.h
			$(CC) $(CFLAGS) -c connect.c

clean:
		rm -rf $(OBJ) $(TARGET)
