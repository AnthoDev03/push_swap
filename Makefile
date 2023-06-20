NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -Llibft -lft -Lft_printf -lftprintf

SRCS = srcs/main.c \
       srcs/utils.c \
       srcs/swap.c \
       srcs/push.c \
       srcs/rotate.c \
       srcs/reverse_rotate.c \
       srcs/parse.c

OBJS = $(SRCS:.c=.o)

HEADER = includes/push_swap.h

LIBFT = libft/libft.a

FT_PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(HEADER) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft/

$(FT_PRINTF):
	make -C ft_printf/

clean:
	rm -f $(OBJS)
	make -C libft/ clean
	make -C ft_printf/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C ft_printf/ fclean

re: fclean all

.PHONY: all clean fclean re

# Utilisation du makefile de libft
$(LIBFT):
	make -C libft/

# Utilisation du makefile de ft_printf
$(FT_PRINTF):
	make -C ft_printf/

