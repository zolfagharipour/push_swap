/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:01:55 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/10/27 15:01:58 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <strings.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define DOWN 0
# define UP 1
# define A 0
# define B 1

typedef struct s_pushswap{
	int	*list[2];
	int	len[2];

}	t_pushswap;

int		push(t_pushswap *dlist, int from);
void	rotate(t_pushswap dlist, int st, int dir);
void	swap(t_pushswap *dlist, int st);

int		s_exist(t_pushswap dlist, int i, int len);
int		series(t_pushswap *dlist, int op);
int		ft_abs(int nbr);

int		detach(t_pushswap *dlist);

int		*assign_values(t_pushswap dlist);
int		smallest(int *list, int len);
int		nbr_moves(t_pushswap dlist, int i, int j);
int		check_placement(t_pushswap dlist, int i);
int		ft_sort(t_pushswap *dlist);

int		duplicate(t_pushswap dlist);
int		ft_read(t_pushswap *dlist, int ac, char **av);
int		init(t_pushswap *dlist, int ac);

int		instruction_read(t_pushswap *dlist);

#endif
