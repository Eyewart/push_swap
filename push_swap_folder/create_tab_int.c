/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:35:10 by Hassan            #+#    #+#             */
/*   Updated: 2022/12/29 18:40:00 by hrifi-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_make_tab(int N, char **arg)
{
	int		*tab;
	int		i;

	tab = malloc (sizeof(int) * N);
	if (!tab)
		ft_exit();
	i = 0;
	while (i < N)
	{
		if (arg[i][0] == 0)
			ft_exit();
		tab[i] = ft_atoi(arg[i]);
		i++;
	}
	return (tab);
}

void	ft_bubblesort(int **list_int, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (list_int[0][i] > list_int[0][j])
			{
				tmp = list_int[0][j];
				list_int[0][j] = list_int[0][i];
				list_int[0][i] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*ft_copy_tab(int *list_int, int size)
{
	int	i;
	int	*new_list_int;

	i = 0;
	new_list_int = malloc(sizeof(int) * size);
	if (!new_list_int)
		ft_exit();
	while (i < size)
	{
		new_list_int[i] = list_int[i];
		i++;
	}
	return (new_list_int);
}
