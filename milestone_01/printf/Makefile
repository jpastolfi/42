FLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
SRC=ft_printf.c
OBJS=${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} $^

%.o:%.c
	cc -c ${FLAGS} $< -o $@

fclean: clean
	rm -rf ${NAME}

re:  fclean all

.PHONY: all clean fclean re