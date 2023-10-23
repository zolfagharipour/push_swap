#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <strings.h>
# include <stdlib.h>

typedef struct s_list{
	int	*list[2];
	int	len[2];

} t_list;


int	push(t_list *dlist, int l_from);
void	rotate(t_list dlist, int l, int dir);
void	swap(t_list *dlist, int l);

int	s_exist(t_list dlist, int i, int len);
int	series(t_list *dlist, int op);
int	ft_abs(int nbr);


#endif