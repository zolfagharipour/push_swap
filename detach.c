#include "pushswap.h"

static int	ft_init(t_list *dlist)
{
	int	i;
	int dir;
	int ret;

	i = dlist->len[0] - (series(dlist, 0) + series(dlist, 1));
	dir = 0;
	if (i < 0)
		dir = 1;
	ret = series(dlist, 0) + i;
	i = abs(i);
	while(i > 0)
	{
		rotate(*dlist, 0, dir);
		if (dir == 0)
			printf("rra\n");
		else
			printf("ra\n");
		i--;
	}
	return (ret);
}

static int	swap_series(t_list *dlist)
{
	int	i;

	i = 0;
	swap(dlist, 0);

	while (!s_exist(*dlist, i, dlist->len[0]) && i < dlist->len[0])
		i++;
	if (i == dlist->len[0])
	{
		swap(dlist, 0);
		return (0);
	}
	printf("sa\n");
	return (1);

}


static int	swap_check(t_list *dlist, int i_serie)
{
	if (swap_series(dlist))
		return (1);
	if (i_serie < 2 || dlist->list[0][0] < dlist->list[0][1])
		return (0);
	if (i_serie > 4 && dlist->list[0][2] > dlist->list[0][3])
		return (0);
	if (dlist->len[1] > 1 && dlist->list[1][0] < dlist->list[1][1])
	{
		swap(dlist, 0);
		swap(dlist, 1);
		printf("ss\n");
	}
	else
	{
		swap(dlist, 0);
		printf("sa\n");
	}
	return (1);
}

int	detach(t_list *dlist)
{
	int	i_serie;

	i_serie = ft_init(dlist);
	while(0 < i_serie)
	{
		swap_check(dlist, i_serie);
		if (s_exist(*dlist, -1, dlist->len[0]))
			return (1);
		if (!push(dlist, 0))
			return (0);
		printf("pa\n");
		i_serie--;
		if (s_exist(*dlist, -1, dlist->len[0]))
			return (1);
	}
	return (1);
}

// void	print_list(t_list dlist, int x)
// {
// 	int	i = 0;
// 	printf("\n");
// 	while (i < x)
// 	{
// 		if (dlist.len[0] > i)
// 			printf("%d	", dlist.list[0][i]);
// 		else
// 			printf(".	");
// 		if (dlist.len[1] > i)
// 			printf("%d\n", dlist.list[1][i]);
// 		else
// 			printf(".\n");
// 		i++;
// 	}
// 	printf("\n");
// }

// int	main()
// {
// 	int	i = 0;
// 	int x = 7;
// 	t_list	dlist;

// 	//dlist.len = (int *)malloc(sizeof(int) * 2);
// 	//dlist.len[1] = (int)malloc(sizeof(int));
// 	dlist.list[0] = (int *)malloc(sizeof(int) * x);
// 	dlist.len[0] = x;
// 	dlist.list[1] = (int *)malloc(sizeof(int) * 0);
// 	dlist.len[1] = 0;

// 	while (i < dlist.len[0])
// 	{
// 		dlist.list[0][i] = i + 1;
// 		i++;
// 	}
// 	dlist.list[0][0] =7;
// 	dlist.list[0][1] =6;
// 	dlist.list[0][2] =5;
// 	dlist.list[0][3] =4;
// 	dlist.list[0][4] =3;
// 	dlist.list[0][5] =2;
// 	dlist.list[0][6] =1;
// 	// dlist.list[0][7] =2;
// 	// dlist.list[0][8] =1;


// 	//swap(dlist, 0);
// 	//push(&dlist, 0);
// 	//rotate(dlist, 0, 0);
// 	//rotate(dlist, 0, 0);
	
// 	printf("Indext: %d\nLenght: %d\n", series(&dlist, 0), series(&dlist, 1));

// 	i = 0;
// 	print_list(dlist, x);
// 	printf("\n \n");

// 	detach(&dlist);
	
	
// 	print_list(dlist, x);
// 	free(dlist.list[0]);
// 	free(dlist.list[1]);

// }