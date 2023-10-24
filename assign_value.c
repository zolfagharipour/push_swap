#include "push_swap.h"

int	nbr_moves(t_pushswap dlist, int i, int j)
{
	int	move_up;
	int	move_down;

	move_up = i;
	if (i < j)
	{
		if (j < ((dlist.len[1] - j) + i))
			move_up = j;
		else
			move_up = ft_abs(dlist.len[1] - j) + i;
	}
	move_down = dlist.len[0] - i;
	if (dlist.len[0] - i < dlist.len[1] - j)
	{
		if (dlist.len[1] - j < (dlist.len[0] - i) + j)
			move_down = dlist.len[1] - j;
		else
			move_down = (dlist.len[0] - i) + j;
	}
	if(move_up < move_down)
		return (move_up + 1);
	return (move_down + 1);	
}

int	smallest(int *list, int len)
{
	int	j;
	int	tmp;

	j = 1;
	tmp = 0;
	while (j < len)
	{
		if (list[tmp] > list[j])
			tmp = j;
		j++;
	}
	return (tmp);
}

int	check_placement(t_pushswap dlist, int i)
{
	int nbr;
	int	j;

	j = 0;
	nbr = dlist.list[1][i];
	while(j < dlist.len[0])
	{
		if(nbr < dlist.list[0][j] && nbr > dlist.list[0][(j - 1 + dlist.len[0]) % dlist.len[0]])
			return (j);
		j++;
	}
	return (smallest(dlist.list[0], dlist.len[0]));
}

int	*assign_values(t_pushswap dlist)
{
	int	*values;
	int	i;

	i = 0;
	values = (int *)malloc(sizeof(int) * dlist.len[1]);
	if (!values)
		return (NULL);
	while(i < dlist.len[1])
	{
		values[i] = check_placement(dlist, i);
		values[i] = nbr_moves(dlist, values[i], i);
		i++;
	}
	return (values);
}
