CC		:= gcc
CFLAGS		:= -ansi -pedantic -Wall -Wextra

SRC_DIR		:= src
SRCS		:= $(wildcard $(SRC_DIR)/*.c)

OBJ_DIR		:= out
OBJS		:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TARGET_DIR	:= out/bin
TARGET		:= $(TARGET_DIR)/cqc

all: $(TARGET)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS)


