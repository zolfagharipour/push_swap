#include "pushswap.h"

static int	nbr_moves(t_list dlist, int i, int j)
{
	int	move_up;
	int	move_down;

	move_up = i;
	if (i < j)
	{
		if (j < ((dlist.len[1] - j) + i))
			move_up = j;
		else
			move_up = abs(dlist.len[1] - j) + i;
	}
	move_down = dlist.len[0] - i;
	if (dlist.len[0] - i < dlist.len[1] - j)
	{
		if (dlist.len[1] - j < (dlist.len[0] - i) + j)
			move_down = dlist.len[1] - j;
		else
			move_down = (dlist.len[0] - i) + j;
	}
	if(move_up < move_down)
		return (move_up + 1);
	return (move_down + 1);	
}

int	smallest(int *list, int len)
{
	int	j;
	int	tmp;				//(len[1] - j) same		len[0] - i + j

	j = 0;
	tmp = 0;
	while (j < len)
	{
		if (list[tmp] >= list[j])
			tmp = j;
		j++;
	}
	return (tmp);
}

static int	check_placement(t_list dlist, int i)
{
	int nbr;
	int	j;

	j = 0;
	nbr = dlist.list[1][i];
	while(j < dlist.len[0])
	{
		if(nbr < dlist.list[0][j] && nbr > dlist.list[0][(j - 1 + dlist.len[0]) % dlist.len[0]])
			return (j);
		j++;
	}
	return (smallest(dlist.list[0], dlist.len[0]));
}

int	*assign_value(t_list dlist)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * dlist.len[1]);
	if (!tmp)
		return (NULL);
	while(i < dlist.len[1])
	{
		tmp[i] = check_placement(dlist, i);
		tmp[i] = nbr_moves(dlist, tmp[i], i);
		i++;
	}
	return (tmp);
}

void	print_list(t_list dlist, int x, int *tmp)
{
	int	i = 0;
	printf("\n");
	while (i < x)
	{
		if (dlist.len[0] > i)
			printf("%d	", dlist.list[0][i]);
		else
			printf(".	");
		if (dlist.len[1] > i)
			printf("%d	", dlist.list[1][i]);
		else
			printf(".	");		
		if (dlist.len[1] > i)
			printf("%d\n", tmp[i]);
		else
			printf(".\n");
		i++;
	}
	printf("\n");
}

int	main()
{
	int	i = 0;
	int x = 9;
	int	*values;
	t_list	dlist;

	//dlist.len = (int *)malloc(sizeof(int) * 2);
	//dlist.len[1] = (int)malloc(sizeof(int));
	dlist.list[0] = (int *)malloc(sizeof(int) * x);
	dlist.len[0] = x;
	dlist.list[1] = (int *)malloc(sizeof(int) * 0);
	dlist.len[1] = 0;

	while (i < dlist.len[0])
	{
		dlist.list[0][i] = i + 1;
		i++;
	}
	dlist.list[0][0] =18;
	dlist.list[0][1] =2;
	dlist.list[0][2] =8;
	dlist.list[0][3] =100;
	dlist.list[0][4] =4;
	dlist.list[0][5] =10;
	dlist.list[0][6] =12;
	dlist.list[0][7] =114;
	dlist.list[0][8] =16;

	// dlist.list[1][0] =1;
	// dlist.list[1][1] =-1;
	// dlist.list[1][2] =15;
	// dlist.list[1][3] =3;
	// dlist.list[1][4] =3;
	// dlist.list[0][5] =2;
	// dlist.list[0][6] =1;
	// dlist.list[0][7] =2;
	// dlist.list[0][8] =1;


	printf("Indext: %d\nLenght: %d\n", series(&dlist, 0), series(&dlist, 1));

	i = 0;
	//print_list(dlist, x, values);
	printf("\n \n");
	detach (&dlist);
	values = assign_value(dlist);
	
	
	print_list(dlist, x, values);
	free(values);
	free(dlist.list[0]);
	free(dlist.list[1]);

}