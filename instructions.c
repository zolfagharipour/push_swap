/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:53:22 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/10/27 14:53:24 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pushswap *dlist, int st)
{
	int	tmp;

	tmp = dlist->list[st][0];
	dlist->list[st][0] = dlist->list[st][1];
	dlist->list[st][1] = tmp;
}

void	rotate(t_pushswap dlist, int st, int dir)
{
	int	tmp;
	int	i;

	if (dir == UP)
	{
		tmp = dlist.list[st][0];
		i = 1;
		while (i < dlist.len[st])
		{
			dlist.list[st][i - 1] = dlist.list[st][i];
			i++;
		}
		dlist.list[st][i - 1] = tmp;
	}
	else if (dir == DOWN)
	{
		tmp = dlist.list[st][dlist.len[st] - 1];
		i = dlist.len[st] - 1;
		while (i > 0)
		{
			dlist.list[st][i] = dlist.list[st][i - 1];
			i--;
		}
		dlist.list[st][0] = tmp;
	}
}

static void	push_reassign(t_pushswap *dlist, int **tmp, int from)
{
	int	to;

	to = (from * from - 1) * -1;
	dlist->len[from]--;
	dlist->len[to]++;
	free(dlist->list[from]);
	dlist->list[from] = tmp[from];
	free(dlist->list[to]);
	dlist->list[to] = tmp[to];
}

int	push(t_pushswap *dlist, int from)
{
	int	*tmp[2];
	int	to;
	int	i;

	to = (from * from - 1) * -1;
	tmp[from] = (int *)malloc(sizeof(int) * (dlist->len[from] - 1));
	if (!tmp[from])
		return (0);
	tmp[to] = (int *)malloc(sizeof(int) * (dlist->len[to] + 1));
	if (!tmp[to])
		return (free(tmp[from]), 0);
	i = 0;
	tmp[to][0] = dlist->list[from][0];
	while (dlist->len[from] > i + 1 || dlist->len[to] > i)
	{
		if (dlist->len[from] > i + 1)
			tmp[from][i] = dlist->list[from][i + 1];
		if (dlist->len[to] > i)
			tmp[to][i + 1] = dlist->list[to][i];
		i++;
	}
	push_reassign(dlist, tmp, from);
	return (1);
}
