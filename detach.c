/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detach.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:51:29 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/10/27 14:51:31 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_init(t_pushswap *dlist)
{
	int	i;
	int	dir;
	int	ret;

	i = dlist->len[A] - (series(dlist, 0) + series(dlist, 1));
	dir = 0;
	if (i < 0)
		dir = 1;
	ret = series(dlist, 0) + i;
	i = ft_abs(i);
	while (i > 0)
	{
		rotate(*dlist, 0, dir);
		if (dir == 0)
			write(1, "rra\n", 4);
		else
			write(1, "ra\n", 3);
		i--;
	}
	return (ret);
}

static int	swap_series(t_pushswap *dlist)
{
	int	i;

	i = 0;
	swap(dlist, A);
	if (s_exist(*dlist, -1, dlist->len[A]) && i < dlist->len[A])
	{
		write(1, "sa\n", 3);
		return (1);
	}
	else
	{
		swap(dlist, A);
		return (0);
	}
}

static int	swap_check(t_pushswap *dlist, int i_serie)
{
	if (swap_series(dlist))
		return (1);
	if (i_serie < 2 || dlist->list[A][0] < dlist->list[A][1])
		return (0);
	if (i_serie > 4 && dlist->list[A][2] > dlist->list[A][3])
		return (0);
	if (dlist->len[B] > 1 && dlist->list[B][0] < dlist->list[B][1])
	{
		swap(dlist, A);
		swap(dlist, B);
		write(1, "ss\n", 3);
	}
	return (1);
}

int	detach(t_pushswap *dlist)
{
	int	i_serie;

	i_serie = ft_init(dlist);
	while (0 <= i_serie)
	{
		swap_check(dlist, i_serie);
		if (s_exist(*dlist, -1, dlist->len[A]))
			return (1);
		if (!push(dlist, A))
			return (free(dlist->list[A]), free(dlist->list[B]), 0);
		write (1, "pb\n", 3);
		i_serie--;
		if (s_exist(*dlist, -1, dlist->len[A]))
			return (1);
	}
	return (1);
}
