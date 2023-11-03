
NAME = push_swap
CHECK = checker

SRCS =  assign_value.c \
		instructions.c \
		series.c \
		sort.c \
		tester.c \
		detach.c \
		push_swap.c \
		list_init.c

BONUS = checker.c \
		assign_value.c \
		instructions.c \
		series.c \
		sort.c \
		tester.c \
		detach.c \
		list_init.c

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}


CC = cc
CFLAGS = -Wall -Wextra -Werror
RM	=	rm -rf

all: ${NAME}
${NAME}: ${SRCS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${SRCS} ./libft/libft.a -o ${NAME}

${CHEK}: ${BONUS}

bonus: ${CHEK} ${SRCS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${BONUS} ./libft/libft.a -o ${CHECK}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS} ${BONUS_OBJS}


fclean: clean
	@${RM} ${NAME} ${CHECK}

re: fclean all

.PHONY: all bonus clean fclean re