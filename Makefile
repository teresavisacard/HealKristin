CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -O3
TARGET  = healkristin

SRCS = main.c load.c manager.c connectivity.c tasks.c
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
CC     = gcc
CFLAGS = -Wall -Wextra -std=c99 -O3
SRCS   = main.c load.c manager.c connectivity.c tasks.c

healkristin: $(SRCS) data.h load.h manager.h tasks.h
	$(CC) $(CFLAGS) $(SRCS) -o healkristin

valgrind: $(SRCS) data.h load.h manager.h tasks.h
	$(CC) -Wall -Wextra -std=c99 -g -O0 $(SRCS) -o healkristin_debug
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

clean:
	rm -f healkristin