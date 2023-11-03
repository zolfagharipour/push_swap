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
			(write(1, "rr\n", 3), rotate(*dlist, 1, UP), rotate(*dlist, 0, UP));
		else if (rotate_a == 0 && rotate_b > 0)
			(write(1, "rb\n", 3), rotate(*dlist, 1, UP));
		else if (rotate_a > 0 && rotate_b == 0)
			(write(1, "ra\n", 3), rotate(*dlist, 0, UP));
		else if (rotate_a < 0 && rotate_b < 0)
			(write(1, "rrr\n", 4), rotate(*dlist, 1, DOWN), rotate(*dlist, 0, DOWN));
		else if (rotate_a == 0 && rotate_b < 0)
			(write(1, "rrb\n", 4), rotate(*dlist, 1, DOWN));
		else if (rotate_a < 0 && rotate_b == 0)
			(write(1, "rra\n", 4), rotate(*dlist, 0, DOWN));
		else if (rotate_a < 0 && rotate_b > 0)
		{
			(write(1, "rra\n", 4), rotate(*dlist, 0, DOWN));
			(write(1, "rb\n", 3), rotate(*dlist, 1, UP));
		}
		else if (rotate_a > 0 && rotate_b < 0)
		{
			(write(1, "ra\n", 3), rotate(*dlist, 0, UP));
			(write(1, "rrb\n", 4), rotate(*dlist, 1, DOWN));
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
	while (0 < dlist->len[B])
	{
		values = assign_values(*dlist);
		if (!values)
		{
			free(dlist->list[A]);
			free(dlist->list[B]);
			return (0);
		}
		min = smallest(values, dlist->len[B]);
		i = check_placement(*dlist, min);
		if (dlist->len[A] - i < i)
			i = i - dlist->len[A];
		if (dlist->len[B] - min < min)
			min = min - dlist->len[B];
		rotate_print(dlist, i, min);
		free (values);
		if (!push(dlist, B))
			return (free(dlist->list[A]), free(dlist->list[B]), 0);
		write(1, "pa\n", 3);
	}
	min = smallest(dlist->list[A], dlist->len[A]);
	if (dlist->len[A] - min > min)
		rotate_print(dlist, min, 0);
	else
		rotate_print(dlist, min - dlist->len[A], 0);
	return (1);
}
