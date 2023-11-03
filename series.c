/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   series.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:57:02 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/10/27 14:57:03 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	s_exist(t_pushswap dlist, int i, int len)
{
	int	j;
	int	k;

	k = i;
	if (i == -1)
	{
		k = dlist.len[0] - 1;
		i = 0;
	}
	while (i <= k)
	{
		j = 0;
		while (dlist.list[0][(i + j) % dlist.len[0]]
			< dlist.list[0][(i + j + 1) % dlist.len[0]])
		{
			j++;
		}
		if (j + 1 == len)
			return (1);
		i++;
	}
	return (0);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

static int	optimum(t_pushswap dlist, int len)
{
	int	i;
	int	opt;
	int	ret;

	if (len <= 3)
		return (dlist.len[0] - 3);
	i = 0;
	ret = 0;
	opt = dlist.len[0];
	while (i < dlist.len[0])
	{
		if (s_exist(dlist, i, len) && opt > ft_abs(i + len - dlist.len[0]))
		{
			opt = ft_abs(i + len - dlist.len[0]);
			ret = i;
		}
		i++;
	}
	return (ret);
}

int	series(t_pushswap *dlist, int op)
{
	int	len;
	int	i;

	len = dlist->len[0];
	while (len > 3)
	{
		i = 0;
		while (i < dlist->len[0])
		{
			if (s_exist(*dlist, i, len))
			{
				if (op == 0)
					return (optimum(*dlist, len));
				else
					return (len);
			}
			i++;
		}
		len--;
	}
	if (op == 0)
		return (optimum(*dlist, len));
	else
		return (len);
}
