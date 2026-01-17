CC = cc
CFLAGS = -Wall -Wextra -g
OBJ = dup.o connect.o conf.o helper.o logger.o
TARGET = bin/dup

$TARGET: $(OBJ)
			$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

dup.o: dup.c connect.h
			$(CC) $(CFLAGS) -c dup.c

connect.o: connect.c connect.h
			$(CC) $(CFLAGS) -c connect.c

conf.o: conf.c conf.h
			$(CC) $(CFLAGS) -c conf.c

helper.o: helper.c helper.h
			$(CC) $(CFLAGS) -c helper.c

logger.o: logger.c logger.h
			$(CC) $(CFLAGS) -c logger.c
clean:
		rm -rf $(OBJ) $(TARGET)
