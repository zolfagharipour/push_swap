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

int	push(t_pushswap *dlist, int from)
{
	int	*tmpf;
	int	*tmpt;
	int	to;
	int	i;

	to = (from * from - 1) * -1;
	tmpf = (int *)malloc(sizeof(int) * (dlist->len[from] - 1));
	if (!tmpf)
		return (0);
	tmpt = (int *)malloc(sizeof(int) * (dlist->len[to] + 1));
	if (!tmpt)
		return (free(tmpf), 0);
	i = 0;
	tmpt[0] = dlist->list[from][0];
	while (dlist->len[from] > i + 1 || dlist->len[to] > i)
	{
		if (dlist->len[from] > i + 1)
			tmpf[i] = dlist->list[from][i + 1];
		if (dlist->len[to] > i)
			tmpt[i + 1] = dlist->list[to][i];
		i++;
	}
	dlist->len[from]--;
	dlist->len[to]++;
	free(dlist->list[from]);
	dlist->list[from] = tmpf;
	free(dlist->list[to]);
	dlist->list[to] = tmpt;
	return (1);
}
