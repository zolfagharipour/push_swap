/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:48:35 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/10/27 14:48:38 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	push_check(char *str)
{
	if (!ft_strncmp(str, "pa", 2) || !ft_strncmp(str, "pb", 2))
		return (1);
	write(2, "Error\n", 7);
	free(str);
	return (0);
}

static int	instruction_do(t_pushswap *dlist, char *str)
{
	if (!ft_strncmp(str, "pa", 2) && !push(dlist, B))
		return (free(str), 0);
	else if (!ft_strncmp(str, "pb", 2) && !push(dlist, A))
		return (free(str), 0);
	else if (!ft_strncmp(str, "ra", 2))
		return (rotate(*dlist, A, UP), 1);
	else if (!ft_strncmp(str, "rb", 2))
		return (rotate(*dlist, B, UP), 1);
	else if (!ft_strncmp(str, "rr", 3))
		return (rotate(*dlist, A, UP), rotate(*dlist, B, UP), 1);
	else if (!ft_strncmp(str, "rra", 3))
		return (rotate(*dlist, A, DOWN), 1);
	else if (!ft_strncmp(str, "rrb", 3))
		return (rotate(*dlist, B, DOWN), 1);
	else if (!ft_strncmp(str, "rrr", 3))
		return (rotate(*dlist, A, DOWN), rotate(*dlist, B, DOWN), 1);
	else if (!ft_strncmp(str, "sa", 2))
		return (swap(dlist, A), 1);
	else if (!ft_strncmp(str, "sb", 2))
		return (swap(dlist, B), 1);
	else if (!ft_strncmp(str, "ss", 2))
		return (swap(dlist, A), swap(dlist, B), 1);
	return (push_check(str));
}

static int	line_loop(t_pushswap *dlist)
{
	int		i;
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		i = 0;
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		str[i] = '\0';
		if (ft_strlen(str) > 3 || (ft_strlen(str) == 3
				&& ft_strncmp(str, "rr", 2)))
		{
			write(2, "Error\n", 7);
			return (free(str), 0);
		}
		if (!instruction_do(dlist, str))
			return (0);
		free(str);
		str = get_next_line(0);
	}
	free(str);
	return (1);
}

int	instruction_read(t_pushswap *dlist)
{
	if (!line_loop(dlist))
		return (0);
	if (s_exist(*dlist, 0, dlist->len[A]) && dlist->len[B] == 0)
	{
		write(1, "OK\n", 3);
		return (1);
	}
	write(1, "KO\n", 3);
	return (0);
}

int	main(int ac, char **av)
{
	t_pushswap	dlist;

	if (!init(&dlist, ac) || !ft_read(&dlist, ac, av) || !duplicate(dlist))
	{
		free(dlist.list[A]);
		free(dlist.list[B]);
		return (0);
	}
	if (!instruction_read(&dlist))
	{
		free(dlist.list[A]);
		free(dlist.list[B]);
		return (0);
	}
	free(dlist.list[A]);
	free(dlist.list[B]);
	return (1);
}
