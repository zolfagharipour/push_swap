// #include "push_swap.h"

// void generateList(int arr[], int size) {
//     int i, j, num, isRepeated;
//     srand(time(0)); // use current time as seed for random generator

//     for(i = 0; i < size; i++) {
//         do {
//             num = rand() % size; // generate a random number between 0 and 9
//             isRepeated = 0; // flag to check if number is already in the array

//             for(j = 0; j < i; j++) {
//                 if(arr[j] == num) {
//                     isRepeated = 1; // number is already in the array
//                     break;
//                 }
//             }
//         } while(isRepeated);

//         arr[i] = num; // add number to the array
//     }
// }



// void	print_pushswap(t_pushswap dlist, int *values)
// {
// 	int	i = 0;
// 	printf("\n");
// 	while (i < dlist.len[0] || i < dlist.len[1])
// 	{
// 		if (dlist.len[0] > i)
// 			printf("%d	", dlist.list[0][i]);
// 		else
// 			printf(".	");
// 		if (dlist.len[1] > i)
// 			printf("%d	", dlist.list[1][i]);
// 		else
// 			printf(".	");		
// 		if (dlist.len[1] > i)
// 			printf("%d\n", values[i]);
// 		else
// 			printf(".\n");
// 		i++;
// 	}
// 	printf("\n");
// }


// int	main()
// {
// 	int	i = 0;
// 	int x = 10;
// 	//int	*values;
// 	t_pushswap	dlist;

// 	dlist.list[0] = (int *)malloc(sizeof(int) * x);
// 	if (!dlist.list[0])
// 		return (0);
// 	dlist.len[0] = x;
// 	dlist.list[1] = (int *)malloc(sizeof(int) * 0);
// 	if (!dlist.list[0])
// 	{
// 		free(dlist.list[0]);
// 		return (0);
// 	}
// 	dlist.len[1] = 0;

// 	while (i < dlist.len[0])
// 	{
// 		dlist.list[0][i] = i + 1;
// 		i++;
// 	}
// 	i = 0;
// 	while(i < 1)
// 	{
// 		generateList(dlist.list[0], x);
// 		if (!ft_sort(&dlist))
// 			return (free(dlist.list[0]), 0);
// 		i++;
// 	}
// 	// dlist.list[0][0] =1;
// 	// dlist.list[0][1] =5;
// 	// dlist.list[0][2] =2;
// 	// dlist.list[0][3] =4;
// 	// dlist.list[0][4] =3;
// 	// dlist.list[0][5] =5;
// 	// dlist.list[0][6] =3;
// 	// dlist.list[0][7] =1;
// 	// dlist.list[0][8] =7;
// 	// dlist.list[0][9] =9;

// 	// dlist.list[1][0] =1;
// 	// dlist.list[1][1] =19;
// 	// dlist.list[1][2] =15;
// 	// dlist.list[1][3] =3;
// 	// dlist.list[1][4] =3;
// 	// dlist.list[0][5] =2;
// 	// dlist.list[0][6] =1;
// 	// dlist.list[0][7] =2;
// 	// dlist.list[0][8] =1;



// 	// print_pushswap(dlist, dlist.list[1]);
// 	// printf("\n \n");
// 	//detach (&dlist);
// 	//values = assign_values(dlist);
	
// 	// print_pushswap(dlist, values);
// 	//free(values);
// 	free(dlist.list[0]);
// 	free(dlist.list[1]);

// }
