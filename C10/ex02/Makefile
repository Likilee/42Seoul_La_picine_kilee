.SUFFIXEX : .c .o
TARGET = ft_tail
CC = gcc
SRC = ft_tail.c
OBJECT = ft_tail.o
CFLAGS = -Wall -Wextra -Werror

all : $(TARGET)

clean :
	rm -f $(OBJECT)
fclean : clean
	rm -f $(TARGET)
re : fclean all

$(TARGET) : $(OBJECT)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECT)

%.o : %.c
	$(CC) $(CFLAGS) -c $(SRC)

.PHONY : all clean fclean re
