NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -Llibft -lft 
SRCS = srcs/main.c \
       srcs/stack_init.c \
       srcs/utils.c \
       srcs/swap.c \
       srcs/push.c \
       srcs/rotate.c \
       srcs/reverse_rotate.c \
       srcs/parse.c \
       srcs/radix.c \
       srcs/transform.c \
       srcs/transform_b.c

OBJS = $(SRCS:.c=.o)

HEADER = includes/push_swap.h

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(HEADER) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft/

clean:
	rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
