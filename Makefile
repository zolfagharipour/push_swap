
NAME = push_swap
CHECK = checker

SRCS =  $(wildcard *.c)

OBJS = ${SRCS:.c=.o}


CC = cc
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}


fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re