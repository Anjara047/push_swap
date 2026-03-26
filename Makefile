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
		show_benchmark.c convert_binary.c\
		verify_flag.c parse_utils.c\
		push_swap_utils.c

OBJ = $(SRC:.c=.o)
DIR_PRINTF = ft_printf
LIB_PRINTF = $(DIR_PRINTF)/libftprintf.a

all:$(NAME)

$(NAME):$(OBJ)
	@make -C $(DIR_PRINTF)
	@$(CC) $(FLAGS) $(OBJ) $(LIB_PRINTF) -o $(NAME)

clean:
	@make -C $(DIR_PRINTF) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(DIR_PRINTF) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
