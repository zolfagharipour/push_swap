#include "push_swap.h"

int	duplicate(t_pushswap dlist)
{
	int	i;
	int	j;

	i = 0;
	while(i < dlist.len[0] - 1)
	{
		j = i + 1;
		while(j < dlist.len[0])
		{
			if (dlist.list[0][i] == dlist.list[0][j])
			{
				free(dlist.list[0]);
				free(dlist.list[1]);
				write(2, "Error\n", 7);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
int	ft_read(t_pushswap *dlist, int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while(i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			// printf("[%s]", ft_itoa(ft_atoi(av[i])));
			// printf("[%s]", av[1]);
			if (!ft_isdigit(av[i][j]) && (j < 0 || av[i][j] != '-'))
			{
				write(2, "Error\n", 7);	
				return (free(dlist->list[0]), free(dlist->list[1]), 0);
			}
			j++;
		}
		tmp = ft_itoa(ft_atoi(av[i]));
		if (!tmp)
			return(free(dlist->list[0]), free(dlist->list[1]), 0);
		if (ft_strncmp(av[i], tmp, 10))
		{
			write(2, "Error\n", 7);
			return (free(dlist->list[0]), free(dlist->list[1]), 0);
		}
		free(tmp);
		dlist->list[0][i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (1);
}

int	init(t_pushswap *dlist, int ac)
{
	if (ac == 1)
		return (0);
	dlist->list[0] = (int *)malloc(sizeof(int) * (ac - 1));
	if (!dlist->list[0])
		return (0);
	dlist->len[0] = ac - 1;
	dlist->list[1] = (int *)malloc(0);
	if (!dlist->list[0])
		return (free(dlist->list[0]), 0);
	dlist->len[1] = 0;
	return (1);
}

int main (int ac, char **av)
{
	t_pushswap	dlist;

	if (!init(&dlist, ac) || !ft_read(&dlist, ac, av) || !duplicate(dlist))
		return (0);
	if (!ft_sort(&dlist))
		return (free(dlist.list[0]), 0);
	free(dlist.list[0]);
	free(dlist.list[1]);
	return (1);
}