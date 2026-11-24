NAME        = push_swap
BONUS		= checker
# SRCS_START
SRCS        = ft_compute_disorder.c ft_linked_list_additions.c ft_linked_list.c \
              ft_parse_input.c ft_push_operations.c ft_radix_lsd.c ft_reverse_operations.c ft_rotate_operations.c \
              ft_runner.c ft_stack_error.c ft_swap_operations.c range_sort.c small_sort.c sort_aux.c turk_sort.c
# SRCS_END

OBJS        = $(SRCS:.c=.o)

HEADER      = push_swap.h

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a
INCLUDES    = -I. -I$(LIBFT_DIR)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
RM          = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) main.o
	$(CC) $(CFLAGS) $(OBJS) main.c -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# clean deletes main.o and checker.o only if exists
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) main.o checker.o checker_aux.o

# clean deletes checker only if exists
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) checker

re: fclean all

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(OBJS) checker.o checker_aux.o
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) checker.c checker_aux.c -lft -o $(BONUS)

.PHONY: all clean fclean re
