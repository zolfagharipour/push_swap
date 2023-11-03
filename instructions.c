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

void	swap(t_pushswap *dlist, int l)
{
	int	tmp;

	tmp = dlist->list[l][0];
	dlist->list[l][0] = dlist->list[l][1];
	dlist->list[l][1] = tmp;
}

void	rotate(t_pushswap dlist, int l, int dir)
{
	int	tmp;
	int	i;

	if (dir == 1)
	{
		tmp = dlist.list[l][0];
		i = 1;
		while (i < dlist.len[l])
		{
			dlist.list[l][i - 1] = dlist.list[l][i];
			i++;
		}
		dlist.list[l][i - 1] = tmp;
	}
	else if (dir == 0)
	{
		tmp = dlist.list[l][dlist.len[l] - 1];
		i = dlist.len[l] - 1;
		while (i > 0)
		{
			dlist.list[l][i] = dlist.list[l][i - 1];
			i--;
		}
		dlist.list[l][0] = tmp;
	}
}

int	push(t_pushswap *dlist, int l_from)
{
	int	*tmpf;
	int	*tmpt;
	int	l_to;
	int	i;

	l_to = (l_from * l_from - 1) * -1;
	tmpf = (int *)malloc(sizeof(int) * (dlist->len[l_from] - 1));
	if (!tmpf)
		return (0);
	tmpt = (int *)malloc(sizeof(int) * (dlist->len[l_to] + 1));
	if (!tmpt)
		return (free(tmpf), 0);
	i = 0;
	tmpt[0] = dlist->list[l_from][0];
	while (dlist->len[l_from] > i + 1 || dlist->len[l_to] > i)
	{
		if (dlist->len[l_from] > i + 1)
			tmpf[i] = dlist->list[l_from][i + 1];
		if (dlist->len[l_to] > i)
			tmpt[i + 1] = dlist->list[l_to][i];
		i++;
	}
	dlist->len[l_from]--;
	dlist->len[l_to]++;
	free(dlist->list[l_from]);
	dlist->list[l_from] = tmpf;
	free(dlist->list[l_to]);
	dlist->list[l_to] = tmpt;
	return (1);
}
