.SUFFIXEX : .c .o
CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = ft_display_file
SRC = ft_display_file.c
OBJECT = $(SRC:.c=.o)

all : $(TARGET)

clean :
	rm -rf $(OBJECT)
fclean : clean
	rm -rf $(TARGET)
re : fclean all

$(TARGET) : $(OBJECT)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECT)
%.o : %.c
	$(CC) $(CFLAGS) -c $(SRC)
.PHONY : all clean fclean re
