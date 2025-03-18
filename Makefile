NAME        = push_swap
CC          = cc
RM          = rm -f
CFLAGS      = -Wall -Wextra -Werror

PRINTF      = ft_printf/

SRCS = checker.c free_and_error.c init_to_stack_a.c init_to_stack_b.c \
       linked_list.c move_cont_two.c move_cont.c move.c push_swap.c \
       push.c sort_stack.c sorted_three.c stack_a.c utils_one.c utils_two.c \

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF)/libftprintf.a -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(PRINTF)
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C $(PRINTF)
	@rm -rf $(NAME)

re: fclean all
