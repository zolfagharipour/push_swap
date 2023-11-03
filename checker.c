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

static int	instruction_do(t_pushswap *dlist, char *str)
{
	if (!ft_strncmp(str, "pa", 2) && !push(dlist, 1))
		return (free(str), 0);
	else if (!ft_strncmp(str, "pb", 2) && !push(dlist, 0))
		return (free(str), 0);
	else if (!ft_strncmp(str, "ra", 2))
		return (rotate(*dlist, 0, 1), 1);
	else if (!ft_strncmp(str, "rb", 2))
		return (rotate(*dlist, 1, 1), 1);
	else if (!ft_strncmp(str, "rr", 2))
		return (rotate(*dlist, 0, 1), rotate(*dlist, 1, 1), 1);
	else if (!ft_strncmp(str, "rra", 3))
		return (rotate(*dlist, 0, 0), 1);
	else if (!ft_strncmp(str, "rrb", 3))
		return (rotate(*dlist, 1, 0), 1);
	else if (!ft_strncmp(str, "rrr", 3))
		return (rotate(*dlist, 0, 0), rotate(*dlist, 1, 0), 1);
	else if (!ft_strncmp(str, "sa", 2))
		return (swap(dlist, 0), 1);
	else if (!ft_strncmp(str, "sb", 2))
		return (swap(dlist, 1), 1);
	else if (!ft_strncmp(str, "ss", 2))
		return (swap(dlist, 0), swap(dlist, 1), 1);
	if (!ft_strncmp(str, "pa", 2) || !ft_strncmp(str, "pb", 2))
		return (1);
	write(2, "Error1\n", 7);
	printf("[%s]", str);
	return (free(str), 0);
}

int	instruction_read(t_pushswap *dlist)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (100));
	if (!str)
		return (0);
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
			write(2, "Error2\n", 7);
			return (free(str), 0);
		}
		if (!instruction_do(dlist, str))
			return (0);
		str = get_next_line(0);
	}
	if (s_exist(*dlist, 0, dlist->len[0]) && dlist->len[1] == 0)
	{
		write(1, "OK\n", 3);
		return (free(str), 1);
	}
	write(1, "KO\n", 3);
	return (free(str), 0);
}

int	main(int ac, char **av)
{
	t_pushswap	dlist;

	if (!init(&dlist, ac) || !ft_read(&dlist, ac, av) || !duplicate(dlist))
		return (0);
	if (!instruction_read(&dlist))
		return (0);
	free(dlist.list[0]);
	free(dlist.list[1]);
	return (1);
}
