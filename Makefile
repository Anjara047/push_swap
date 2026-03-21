NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC =  	count_disorder.c adaptive_strategy.c\
		error.c ft_atoi.c ft_split.c\
		utils.c index.c move_a.c\
		move_b.c move_a_ab.c move_b_ab.c\
		move_ab.c strat_utils.c flag_utils.c\
		medium_strategy.c simple_strategy.c\
		complex_strategy.c push_swap.c\

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
