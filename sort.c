/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:57:59 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/10/27 14:58:02 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_print(t_pushswap *dlist, int rotate_a, int rotate_b)
{
	while (rotate_a != 0 || rotate_b != 0)
	{
		if (rotate_a > 0 && rotate_b > 0)
			(printf("rr\n"), rotate(*dlist, 1, 1), rotate(*dlist, 0, 1));
		else if (rotate_a == 0 && rotate_b > 0)
			(printf("rb\n"), rotate(*dlist, 1, 1));
		else if (rotate_a > 0 && rotate_b == 0)
			(printf("ra\n"), rotate(*dlist, 0, 1));
		else if (rotate_a < 0 && rotate_b < 0)
			(printf("rrr\n"), rotate(*dlist, 1, 0), rotate(*dlist, 0, 0));
		else if (rotate_a == 0 && rotate_b < 0)
			(printf("rrb\n"), rotate(*dlist, 1, 0));
		else if (rotate_a < 0 && rotate_b == 0)
			(printf("rra\n"), rotate(*dlist, 0, 0));
		else if (rotate_a < 0 && rotate_b > 0)
		{
			(printf("rra\n"), rotate(*dlist, 0, 0));
			(printf("rb\n"), rotate(*dlist, 1, 1));
		}
		else if (rotate_a > 0 && rotate_b < 0)
		{
			(printf("ra\n"), rotate(*dlist, 0, 1));
			(printf("rrb\n"), rotate(*dlist, 1, 0));
		}
		if (rotate_a != 0)
			rotate_a -= rotate_a / ft_abs(rotate_a);
		if (rotate_b != 0)
			rotate_b -= rotate_b / ft_abs(rotate_b);
	}
}

int	ft_sort(t_pushswap *dlist)
{
	int	*values;
	int	min;
	int	i;

	if (!detach(dlist))
		return (0);
	while (0 < dlist->len[1])
	{
		values = assign_values(*dlist);
		if (!values)
		{
			free(dlist->list[0]);
			free(dlist->list[1]);
			return (0);
		}
		min = smallest(values, dlist->len[1]);
		i = check_placement(*dlist, min);
		if (dlist->len[0] - i < i)
			i = i - dlist->len[0];
		if (dlist->len[1] - min < min)
			min = min - dlist->len[1];
		rotate_print(dlist, i, min);
		free (values);
		if (!push(dlist, 1))
			return (free(dlist->list[0]), free(dlist->list[1]), 0);
		printf("pa\n");
	}
	min = smallest(dlist->list[0], dlist->len[0]);
	if (dlist->len[0] - min > min)
		rotate_print(dlist, min, 0);
	else
		rotate_print(dlist, min - dlist->len[0], 0);
	return (1);
}
