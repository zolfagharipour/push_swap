
NAME = push_swap
CHECK = checker

SRCS =  assign_value.c \
		instructions.c \
		series.c \
		sort.c \
		detach.c \
		push_swap.c \
		list_init.c

BONUS = checker.c \
		assign_value.c \
		instructions.c \
		series.c \
		sort.c \
		detach.c \
		list_init.c

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}


CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM	=	rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	make --no-print-directory -C ./libft
	${CC} ${CFLAGS} -o ${NAME} $^ ./libft/libft.a

bonus: ${BONUS_OBJS}
	make --no-print-directory -C ./libft
	${CC} ${CFLAGS} -o ${CHECK} $^ ./libft/libft.a

clean: 
	make --no-print-directory -C ./libft fclean
	${RM} ${OBJS} ${BONUS_OBJS}


fclean: clean
	${RM} ${NAME} ${CHECK}

re: fclean all

.PHONY: all bonus clean fclean re