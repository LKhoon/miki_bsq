.SUFFIXES : .c .o
CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = bsq

INCLUDES = -I./includes
SRCS_DIR = ./srcs
SRCS = bsq.c \
	   main.c \
	   printer.c \
	   readfile_1.c \
	   readfile_2.c \
	   check_valid_1.c \
	   check_valid_2.c
OBJECTS = $(SRCS:.c=.o)

all : $(TARGET)

clean :
	rm -rf $(OBJECTS)
fclean : clean
	rm -rf $(TARGET)
re : fclean all

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(OBJECTS) :
	$(CC) $(CFLAGS) -c $(addprefix $(SRCS_DIR)/, $(SRCS)) $(INCLUDES)

.PHONY : all clean fclean re
