.SUFFIXEX : .c .o
TARGET = ft_cat
CC = gcc
SRC = ft_cat.c
OBJECT = ft_cat.o
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
