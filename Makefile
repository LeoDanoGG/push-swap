NAME        = push_swap

# SRCS_START
SRCS        = ft_compute_disorder.c	    ft_runner.c \
ft_basic_operations.c		ft_linked_list_additions.c  \
ft_basic_operations_wrapper1.c	ft_linked_list.c	    show_stack.c \
ft_basic_operations_wrapper2.c	ft_parse_input.c \
ft_basic_operations_wrapper3.c	ft_radix_lsd.c main.c #checker.c



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

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: checker

checker: $(LIBFT) $(OBJS)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o checker

.PHONY: all clean fclean re
