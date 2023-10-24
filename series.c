#include "push_swap.h"

int	s_exist(t_list dlist, int i, int len)
{
	int j;
	int k;
	int	l;

	k = i;
	if (i == -1)
	{
		k = dlist.len[0] - 1;
		i = 0;
	}
	while (i <= k)
	{
		j = 0;
		while (dlist.list[0][(i + j) % dlist.len[0]] < dlist.list[0][(i + j + 1) % dlist.len[0]])
		{
			j++;
		}
		if (j + 1 == len)
			return (1);
		i++;
	}
	return (0);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

static int	optimum(t_list dlist, int len)
{
	int	i;
	int	opt;
	int	ret;

	if (len <= 3)
		return (dlist.len[0] - 3);
	i = 0;
	ret = 0;
	opt = dlist.len[0];
	while (i < dlist.len[0])
	{
		if (s_exist(dlist, i, len) && opt > ft_abs(i + len - dlist.len[0]))
		{
			opt = ft_abs(i + len - dlist.len[0]);
			ret = i;
		}
		i++;
	}
	return (ret);
}


int	series(t_list *dlist, int op)
{
	int	len;
	int	i;

	len = dlist->len[0];
	while (len > 3)
	{
		i = 0;
		while (i < dlist->len[0])
		{
			if (s_exist(*dlist, i, len))
			{
				if (op == 0)
					return (optimum(*dlist, len));
				else
					return (len);
			}
			i++;
		}
		len--;
	}
	if (op == 0)
		return (optimum(*dlist, len));
	else
		return (len);
}

// int	main()
// {
// 	int	i = 0;
// 	int x = 5;
// 	t_list	dlist;

	
// 	dlist.list[0] = (int *)malloc(sizeof(int) * x);
// 	dlist.len[0] = x;
// 	dlist.list[1] = (int *)malloc(sizeof(int) * 0);
// 	dlist.len[1] = 0;

// 	while (i < dlist.len[0])
// 	{
// 		dlist.list[0][i] = i + 1;
// 		i++;
// 	}
// 	dlist.list[0][0] =1;
// 	dlist.list[0][1] =5;
// 	dlist.list[0][2] =2;
// 	dlist.list[0][3] =4;
// 	dlist.list[0][4] =3;
// 	// dlist.list[0][5] =1;
// 	// dlist.list[0][6] =2;
// 	// dlist.list[0][7] =5;
// 	// dlist.list[0][8] =8;
// 	i = 0;
// 	//swap(dlist, 0);
// 	//push(&dlist, 0);
// 	//rotate(dlist, 0, 0);
// 	//rotate(dlist, 0, 0);
	
// 	printf("Indext: %d\nLenght: %d\n", series(dlist, 0), series(dlist, 1));

// 	while (i < x)
// 	{
// 		printf("%d	\n", dlist.list[0][i]);
// 		i++;
// 	}
// }