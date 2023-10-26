#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <strings.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# 	include <stdio.h>
#	include <time.h>

typedef struct s_pushswap{
	int	*list[2];
	int	len[2];

} t_pushswap;


int		push(t_pushswap *dlist, int l_to);
void	rotate(t_pushswap dlist, int l, int dir);
void	swap(t_pushswap *dlist, int l);

int	s_exist(t_pushswap dlist, int i, int len);
int	series(t_pushswap *dlist, int op);
int	ft_abs(int nbr);

int	detach(t_pushswap *dlist);

int	*assign_values(t_pushswap dlist);
int	smallest(int *list, int len);
int	nbr_moves(t_pushswap dlist, int i, int j);
int	check_placement(t_pushswap dlist, int i);
int	ft_sort(t_pushswap *dlist);

int	duplicate(t_pushswap dlist);
int	ft_read(t_pushswap *dlist, int ac, char **av);
int	init(t_pushswap *dlist, int ac);

void	print_pushswap(t_pushswap dlist, int *values);

char	*get_next_line(int fd);
int	instruction_read(t_pushswap *dlist);





#endif