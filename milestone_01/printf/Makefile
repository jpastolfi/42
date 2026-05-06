FLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
SRC=ft_printf.c utils.c
OBJS=${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} $^

%.o:%.c
	cc -c ${FLAGS} $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${NAME}

re:  fclean all

.PHONY: all clean fclean re