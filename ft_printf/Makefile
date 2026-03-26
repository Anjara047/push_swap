NAME= libftprintf.a
CC= cc
CCFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_itoa.c ft_printptr.c\
	ft_putchar_fd.c ft_putchar.c ft_putdec.c\
	ft_puthex.c ft_puthexup.c ft_putint.c\
	ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c\
	ft_putudec.c ft_strlen.c ft_putpercent.c\
	print_double.c
 
OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	@ar crs $(NAME) $(OBJ)

%o : %c
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
