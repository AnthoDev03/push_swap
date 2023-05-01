NAME = libftprintf.a
LIBFT = ../libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FT_PRINTF_SRCS = ft_printf.c \
		 ft_printf_hex.c \
		 ft_printf_lib.c \
		 ft_printf_ptr.c \
		 ft_printf_unsigned.c \


LIBFT_SRCS = ../libft/*.c

FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(FT_PRINTF_OBJS) $(LIBFT)
	ar rcs $(NAME) $(FT_PRINTF_OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C ../libft/

clean:
	$(RM) $(FT_PRINTF_OBJS)
	$(MAKE) -C ../libft/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ../libft/ fclean

re: fclean all

.PHONY: all clean fclean re

