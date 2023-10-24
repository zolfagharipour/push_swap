#include "push_swap.h"

static int	ft_init(t_pushswap *dlist)
{
	int	i;
	int dir;
	int ret;

	i = dlist->len[0] - (series(dlist, 0) + series(dlist, 1));
	dir = 0;
	if (i < 0)
		dir = 1;
	ret = series(dlist, 0) + i;
	i = ft_abs(i);
	while(i > 0)
	{
		rotate(*dlist, 0, dir);
		if (dir == 0)
			printf("rra\n");
		else
			printf("ra\n");
		i--;
	}
	return (ret);
}

static int	swap_series(t_pushswap *dlist)
{
	int	i;

	i = 0;
	swap(dlist, 0);

	if (s_exist(*dlist, -1, dlist->len[0]) && i < dlist->len[0])
	{
		printf("sa\n");
		return (1);
	}	
	else
	{
		swap(dlist, 0);
		return (0);
	}

}


static int	swap_check(t_pushswap *dlist, int i_serie)
{
	if (swap_series(dlist))
		return (1);
	if (i_serie < 2 || dlist->list[0][0] < dlist->list[0][1])
		return (0);
	if (i_serie > 4 && dlist->list[0][2] > dlist->list[0][3])
		return (0);
	if (dlist->len[1] > 1 && dlist->list[1][0] < dlist->list[1][1])
	{
		swap(dlist, 0);
		swap(dlist, 1);
		printf("ss\n");
	}
	// else
	// {
	// 	swap(dlist, 0);
	// 	printf("sa\n");
	// }
	return (1);
}

int	detach(t_pushswap *dlist)
{
	int	i_serie;

	i_serie = ft_init(dlist);
	while(0 <= i_serie)
	{
		swap_check(dlist, i_serie);
		if (s_exist(*dlist, -1, dlist->len[0]))
			return (1);
		if (!push(dlist, 0))
			return (free(dlist->list[0]), free(dlist->list[1]), 0);
		printf("pb\n");
		i_serie--;
		if (s_exist(*dlist, -1, dlist->len[0]))
			return (1);
	}
	return (1);
}
