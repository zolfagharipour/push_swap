#include "pushswap.h"


void	swap(t_list *dlist, int l)
{
	int	tmp;

	tmp = dlist->list[l][0];
	dlist->list[l][0] = dlist->list[l][1];
	dlist->list[l][1] = tmp;
}

void	rotate(t_list dlist, int l, int dir)
{
	int	tmp;
	int i;

	if (dir == 1)
	{
		tmp = dlist.list[l][0];
		i = 1;
		while (i < dlist.len[l])
		{
			dlist.list[l][i - 1] = dlist.list[l][i];
			i++;
		}
		dlist.list[l][i - 1] = tmp;
	}
	else if (dir == 0)
	{
		tmp = dlist.list[l][dlist.len[l] - 1];
		i = dlist.len[l] - 1;
		while (i >= 0)
		{
			dlist.list[l][i] = dlist.list[l][i - 1];
			i--;
		}
		dlist.list[l][0] = tmp;
	}
		
	
}

int	push(t_list *dlist, int l_from)
{
	int	*tmpf;
	int	*tmpt;
	int	l_to;
	int i;

	l_to = (l_from * l_from - 1) * -1;
	tmpf = (int *)malloc(sizeof(int) * (dlist->len[l_from] - 1));
	if (!tmpf)
		return (0);
	tmpt = (int *)malloc(sizeof(int) * (dlist->len[l_to] + 1));
	if (!tmpt)
		return(free(tmpf), 0);
	i = 0;
	tmpt[0] = dlist->list[l_from][0];
	while (dlist->len[l_from] > i + 1 || dlist->len[l_to] > i)
	{
		if (dlist->len[l_from] > i + 1)
			tmpf[i] = dlist->list[l_from][i + 1];
		if (dlist->len[l_to] > i)
			tmpt[i + 1] = dlist->list[l_to][i];
		i++;
	}
	dlist->len[l_from]--;
	dlist->len[l_to]++;
	free(dlist->list[l_from]);
	dlist->list[l_from] = tmpf;
	free(dlist->list[l_to]);
	dlist->list[l_to] = tmpt;
	return (1);
}

// int	main()
// {
// 	int	i = 0;
// 	t_list	dlist;
	
// 	dlist.list[0] = (int *)malloc(sizeof(int) * 5);
// 	dlist.len[0] = 5;
// 	dlist.list[1] = (int *)malloc(sizeof(int) * 0);
// 	dlist.len[1] = 0;

// 	while (i < dlist.len[0])
// 	{
// 		dlist.list[0][i] = i + 1;
// 		i++;
// 	}
// 	i = 0;
// 	//swap(dlist, 0);
// 	push(&dlist, 0);
// 	rotate(dlist, 0, 1);
// 	while (dlist.list[0][i] || dlist.list[1][i])
// 	{
// 		printf("%d	", dlist.list[0][i]);
// 		printf("%d\n", dlist.list[1][i]);
// 		i++;
// 	}
// }
