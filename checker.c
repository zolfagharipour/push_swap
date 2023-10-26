#include "checker.h"

int main (int ac, char **av)
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