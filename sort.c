#include "push_swap.h"

// static void	fake_rotate(t_list *dlist, int i, int j)
// {
// 	while (i > 0)
// 	{
// 		rotate(*dlist, 0, 1);
// 		i--;
// 	}
// 	while(j > 0)
// 	{
// 		rotate(*dlist, 1, 1);
// 		j--;
// 	}
// }

static	void	rotate_print(t_list *dlist, int	rotate_a, int rotate_b)
{
	while(rotate_a != 0 || rotate_b != 0)
	{
		if (rotate_a > 0 && rotate_b > 0)
			(printf("rr\n"),rotate(*dlist, 1, 1), rotate(*dlist, 0, 1));
		else if (rotate_a == 0 && rotate_b > 0)
			(printf("rb\n"), rotate(*dlist, 1, 1));
		else if (rotate_a > 0 && rotate_b == 0)
			(printf("ra\n"), rotate(*dlist, 0, 1));
		else if (rotate_a < 0 && rotate_b < 0)
			(printf("rrr\n"), rotate(*dlist, 1, 0), rotate(*dlist, 0, 0));
		else if (rotate_a == 0 && rotate_b < 0)
			(printf("rrb\n"), rotate(*dlist, 1, 0));
		else if (rotate_a < 0 && rotate_b == 0)
			(printf("rra\n"), rotate(*dlist, 0, 0));
		else if (rotate_a < 0 && rotate_b > 0)
		{
			(printf("rra\n"), rotate(*dlist, 0, 0));
			(printf("rb\n"), rotate(*dlist, 1, 1));
		}
		else if (rotate_a > 0 && rotate_b < 0)
		{
			(printf("ra\n"), rotate(*dlist, 0, 1));
			(printf("rrb\n"), rotate(*dlist, 1, 0));
		}
		if (rotate_a != 0)
			rotate_a -= rotate_a / ft_abs(rotate_a);
		if (rotate_b != 0)
			rotate_b -= rotate_b / ft_abs(rotate_b);
	}
}

static void	print_switch(t_list *dlist, int i , int j, int moves)
{
	if (moves == i || moves == j)
	{
		rotate_print(dlist, i, j);
	}
	else if (moves == abs(dlist->len[1] - j) + i)
	{
		rotate_print(dlist, i, j);
	}
	else if(moves == dlist->len[0] - i)
	{
		rotate_print(dlist, i, j);	
	}
	else if(moves == dlist->len[1] - j)
	{
		rotate_print(dlist, i, j);
	}
	else if(moves == ft_abs(i) + j) 
	{
		rotate_print(dlist, i, j);	
	}
}
void	print_list(t_list dlist, int *values)
{
	int	i = 0;
	printf("\n");
	while (i < dlist.len[0] || i < dlist.len[1])
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
			printf("%d\n", values[i]);
		else
			printf(".\n");
		i++;
	}
	printf("\n");
}

int	ft_sort(t_list *dlist)
{
	int	*values;
	int	min;
	int	i;

	if (!detach(dlist))
		return (0);
	while(0 < dlist->len[1])
	{
 		values = assign_values(*dlist);
		if (!values)
		{
			free(dlist->list[0]);
			free(dlist->list[1]);
			return(0);
		}
		// printf(">>>");
		// print_list(*dlist, values);
		min = smallest(values, dlist->len[1]);
 		i = check_placement(*dlist, min);
		if (dlist->len[0] - i < i)
			i = i - dlist->len[0];
		if (dlist->len[1] - min < min)
			min = min - dlist->len[1];
		//print_switch(dlist, i, min, values[min] - 1);
		rotate_print(dlist, i, min);
		//fake_rotate(dlist, i, min);
		free (values);
		if (!push(dlist, 1))
			return (free(dlist->list[0]), free(dlist->list[1]), 0);
		printf("pa\n");
	}
	min = smallest(dlist->list[0], dlist->len[0]);
	if (dlist->len[0] - min > min)
		rotate_print(dlist, min, 0);
	else
		rotate_print(dlist, min - dlist->len[0], 0);
	return (1);
}

void generateList(int arr[], int size) {
    int i, j, num, isRepeated;
    srand(time(0)); // use current time as seed for random generator

    for(i = 0; i < size; i++) {
        do {
            num = rand() % size; // generate a random number between 0 and 9
            isRepeated = 0; // flag to check if number is already in the array

            for(j = 0; j < i; j++) {
                if(arr[j] == num) {
                    isRepeated = 1; // number is already in the array
                    break;
                }
            }
        } while(isRepeated);

        arr[i] = num; // add number to the array
    }
}


int	main()
{
	int	i = 0;
	int x = 10;
	int	*values;
	t_list	dlist;

	dlist.list[0] = (int *)malloc(sizeof(int) * x);
	if (!dlist.list[0])
		return (0);
	dlist.len[0] = x;
	dlist.list[1] = (int *)malloc(sizeof(int) * 0);
	if (!dlist.list[0])
	{
		free(dlist.list[0]);
		return (0);
	}
	dlist.len[1] = 0;

	while (i < dlist.len[0])
	{
		dlist.list[0][i] = i + 1;
		i++;
	}
	i = 0;
	while(i < 1)
	{
		generateList(dlist.list[0], x);
		if (!ft_sort(&dlist))
			return (free(dlist.list[0]), 0);
		i++;
	}
	// dlist.list[0][0] =1;
	// dlist.list[0][1] =5;
	// dlist.list[0][2] =2;
	// dlist.list[0][3] =4;
	// dlist.list[0][4] =3;
	// dlist.list[0][5] =5;
	// dlist.list[0][6] =3;
	// dlist.list[0][7] =1;
	// dlist.list[0][8] =7;
	// dlist.list[0][9] =9;

	// dlist.list[1][0] =1;
	// dlist.list[1][1] =19;
	// dlist.list[1][2] =15;
	// dlist.list[1][3] =3;
	// dlist.list[1][4] =3;
	// dlist.list[0][5] =2;
	// dlist.list[0][6] =1;
	// dlist.list[0][7] =2;
	// dlist.list[0][8] =1;



	// print_list(dlist, dlist.list[1]);
	// printf("\n \n");
	//detach (&dlist);
	//values = assign_values(dlist);
	
	// print_list(dlist, values);
	//free(values);
	free(dlist.list[0]);
	free(dlist.list[1]);

}