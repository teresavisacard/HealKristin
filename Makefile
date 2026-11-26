
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -g -O3
TARGET  = healkristin

SRCS = main.c load.c manager.c connectivity.c tasks.c lists.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)