/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:54:49 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/10/27 14:54:51 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pushswap	dlist;

	if (!init(&dlist, ac) || !ft_read(&dlist, ac, av) || !duplicate(dlist))
		return (0);
	if (!ft_sort(&dlist))
		return (free(dlist.list[A]), 0);
	free(dlist.list[A]);
	free(dlist.list[B]);
	return (1);
}
