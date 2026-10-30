NAME        = push_swap

# SRCS_START
SRCS        = ft_basic_operations.c ft_circular_array.c ft_circular_array_operations.c
# SRCS_END

OBJS        = $(SRCS:.c=.o)

HEADER      = push_swap.h

# Library template (libft). For another library with the same layout
# (a folder with its own Makefile that builds a .a), edit LIBFT_DIR,
# LIBFT and the -lft flag in the $(NAME) rule.
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a
INCLUDES    = -I. -I$(LIBFT_DIR)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
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

.PHONY: all clean fclean re
