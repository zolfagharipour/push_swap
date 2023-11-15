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

static int	ft_word_counter(char const *str, char c)
{
	int	word_counter;
	int	word_begin;

	word_begin = 1;
	word_counter = 0;
	while (*str)
	{
		if (word_begin == 1 && *str != c)
		{
			word_counter++;
			word_begin = 0;
		}
		else if (*str == c)
			word_begin = 1;
		str++;
	}
	return (word_counter);
}

static int	write_av(t_pushswap *dlist, char **ptr, int j,	int words)
{
	int	i;
	int	k;

	i = 0;
	while (i < words)
	{
		dlist->list[A][j + i] = ft_atoi(ptr[i]);
		i++;
	}
	k = 0;
	while (ptr[k])
	{
		free(ptr[k]);
		k++;
	}
	free (ptr);
	return (i);
}

static int	*int_realloc(int *s, size_t size_begin, size_t size_add)
{
	size_t	i;
	int		*ptr;

	ptr = (int *)malloc((size_begin + size_add) * sizeof(int));
	if (!ptr)
		return (0);
	i = 0;
	while (i < size_begin)
	{
		ptr[i] = s[i];
		i++;
	}
	free (s);
	return (ptr);
}

int	split_av(t_pushswap *dlist, char *str, int ac, int j)
{
	int		words;
	char	**spl;

	words = ft_word_counter(str, ' ');
	if (words == 1)
	{
		dlist->list[A][j] = ft_atoi(str);
		j++;
	}
	else
	{
		dlist->list[A] = int_realloc(dlist->list[A], ac - 1, words);
		dlist->len[A] += words - 1;
		if (!dlist->list[A])
			return (0);
		spl = ft_split(str, ' ');
		if (!spl)
			return (0);
		j += write_av(dlist, spl, j, words);
	}
	return (j);
}

int	range_zero_check(char *av, char *str)
{
	if (str[0] == '+' && av[0] != '-')
		return (0);
	if (av[0] == '+' || av[0] == '-')
		av++;
	if (str[0] == '-')
		str++;
	while (av && ft_strncmp(av, str, ft_strlen(av)))
	{
		if (av[0] == '0')
			av++;
		else
			return (0);
	}
	return (1);
}
