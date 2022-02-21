NAME = libftprintf.a

LIBFT = libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	@echo "\033[0;92mSUCCESS !!"

$(NAME):
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	#ar rc $(NAME)

clean:
	rm -rf *.o
	make clean -C $(LIBFT)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean fclean re all
