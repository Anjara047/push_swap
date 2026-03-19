NAME = push_swap
CC = cc
FLAGS = -g

SRC = ft_atoi.c utils.c index.c\
		move_a.c move_b.c move_a_ab.c\
		move_b_ab.c move_ab.c strat_utils.c\
		simple_strategy.c medium_strategy.c\
		push_swap.c\

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
