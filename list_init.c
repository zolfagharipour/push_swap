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

int	duplicate(t_pushswap dlist)
{
	int	i;
	int	j;

	i = 0;
	while (i < dlist.len[A] - 1)
	{
		j = i + 1;
		while (j < dlist.len[A])
		{
			if (dlist.list[A][i] == dlist.list[A][j])
			{
				free(dlist.list[A]);
				free(dlist.list[B]);
				write(2, "Error\n", 7);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	digit_check(char *av[], int i)
{
	int	j;

	j = 0;
	while (av[i][j] != '\0')
	{
		if (!ft_isdigit(av[i][j])
			&& (j == 0 && !(av[i][j] != '-' || av[i][j] != '+')))
		{
			write(2, "Error\n", 7);
			return (0);
		}
		j++;
	}
	return (1);
}

static int	range_zero_check(char *av, char * str)
{
	if (str[0] == '-' && av[0] != '-')
		return (0);
	if (av[0] == '+' || av[0] == '-')
		av++;
	if (str[0] == '-')
		str++;
	while(av && ft_strncmp(av, str, ft_strlen(str)))
	{
		if (av[0] == '0')
			av++;
		else
			return (0);
	}
	return (1);
}

int	ft_read(t_pushswap *dlist, int ac, char **av)
{
	int		i;
	char	*tmp;

	i = 1;
	while (i < ac)
	{
		if (!digit_check(av, i))
			return (free(dlist->list[A]), free(dlist->list[B]), 0);
		tmp = ft_itoa(ft_atoi(av[i]));
		if (!tmp)
			return (free(dlist->list[A]), free(dlist->list[B]), 0);
		if (!range_zero_check(av[i], tmp))
		{
			write(2, "Error\n", 7);
			return (free(dlist->list[A]), free(dlist->list[B]), free(tmp), 0);
		}
		free(tmp);
		dlist->list[A][i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (1);
}

int	init(t_pushswap *dlist, int ac)
{
	if (ac == 1)
		return (0);
	dlist->list[A] = (int *)malloc(sizeof(int) * (ac - 1));
	if (!dlist->list[A])
		return (0);
	dlist->len[A] = ac - 1;
	dlist->list[B] = (int *)malloc(0);
	if (!dlist->list[A])
		return (free(dlist->list[A]), 0);
	dlist->len[B] = 0;
	return (1);
}
