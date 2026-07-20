
DIR_INCLUDE = include
DIR_SRC = src
DIR_SRC_OPS = $(DIR_SRC)/ops
DIR_SRC_PARSE = $(DIR_SRC)/parse
DIR_SRC_STRAT = $(DIR_SRC)/strategy

NAME = push_swap.a
PROGRAM = $(NAME:.a=)
LIB_AUX = libft
FLAGS = -Wall -Werror -Wextra -g
HEADER1 = $(DIR_INCLUDE)/push_swap.h
HEADER2 = $(DIR_INCLUDE)/utils.h

SRC = \
$(DIR_SRC)/push_swap.c \
$(DIR_SRC_OPS)/ops_push.c $(DIR_SRC_OPS)/ops_rotate.c $(DIR_SRC_OPS)/ops_rrotate.c $(DIR_SRC_OPS)/ops_swap.c \
$(DIR_SRC_PARSE)/parse_args.c $(DIR_SRC_PARSE)/parse_flags.c $(DIR_SRC_PARSE)/end.c \
$(DIR_SRC_STRAT)/strategy_simple.c $(DIR_SRC_STRAT)/strategy_medium.c $(DIR_SRC_STRAT)/strategy_complex.c \
$(DIR_SRC_STRAT)/strategy_adaptive.c $(DIR_SRC_STRAT)/strategy_small_stack.c $(DIR_SRC_STRAT)/strategy_utils.c

OBJS = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
		make -C $(LIB_AUX)
		cp $(LIB_AUX)/$(LIB_AUX).a $(NAME)
		ar rcs $(NAME) $(OBJS)
		cc $(FLAGS) $(NAME) -o $(PROGRAM)

%.o: %.c $(HEADER1) $(HEADER2)
		cc -c $(FLAGS) $< -o $@

clean:
		make clean -C $(LIB_AUX)
		rm -f $(OBJS)

fclean: clean
		make fclean -C $(LIB_AUX)
		rm -f $(NAME)
		rm -f $(PROGRAM)

re: fclean all

.PHONY: all clean fclean re