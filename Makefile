
NAME = push_swap
CHECK = checker

SRCS =  assign_value.c \
		instructions.c \
		series.c \
		sort.c \
		tester.c \
		detach.c \
		push_swap.c
BONUS = checker.c \
		checker_urils.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}


CC = cc
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

${CHECK}: ${BONUS_OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

bonus: ${CHEK} ${NAME}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${CHECK}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}


fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re