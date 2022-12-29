/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:00:42 by hrifi-la          #+#    #+#             */
/*   Updated: 2022/12/29 14:52:27 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_duplicate(int* list_int, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (list_int[i] == list_int[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

unsigned int ft_count_bits (int n)
{
	int count;

	count = 0;
	while (n)
	{
		count++; //shift operator won't go to negative number
		n >>= 1;
	}
	return (count);
}

int*	ft_sort_indexes(int* sorted_tab, int* saved_tab, int size)
{
	int*	tab_with_indexes;
	int		i;
	int		j;

	tab_with_indexes = malloc(sizeof(int) * size);
	i = 0;
	if (!tab_with_indexes)
		return (NULL);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (saved_tab[i] == sorted_tab[j])
			{
				tab_with_indexes[i] = j;
				break;
			}
			j++;
		}		
		i++;
	}
	return (tab_with_indexes);
}

void	ft_decision_3(list** pileA, list** pileB, int nb_elements)
{
	if (nb_elements <= 1 || ft_is_sorted(*pileA))
		return ;
	while (ft_size_list(pileA) > 3)
		ft_shortsort(pileA, pileB);
	ft_algo_23(pileA); // nb_elements == 2 OR 3
	while ((*pileB) != NULL)
		ft_push(pileB, pileA, 'a');
}

int	main (int argc, char **argv)
{
	list*	pileA;
	list*	pileB;
	int*	tab_of_int;
	int*	save_tab;
	int*	absolute_tab;
	int		nb_bits;
	
	ft_init_list(&pileA);
	tab_of_int = ft_make_tab(argc - 1, &argv[1]);
	if(ft_is_duplicate(tab_of_int, argc - 1))
		ft_exit();
	save_tab = ft_copy_tab(tab_of_int, argc - 1);
	ft_bubblesort(&tab_of_int, argc - 1);
	absolute_tab = ft_sort_indexes(tab_of_int, save_tab, argc - 1);
	free(save_tab);
	free(tab_of_int);
	ft_fill_list(&pileA, absolute_tab, argc - 1);
	free(absolute_tab);
	nb_bits = ft_count_bits (argc - 1);
	ft_init_list(&pileB);
	if (argc - 1 < 10)
		ft_decision_3(&pileA, &pileB, argc - 1);
	else if (!ft_is_sorted(pileA))
		ft_radix(&pileA, &pileB, argc - 1, nb_bits);
	ft_free_list(&pileA);
	ft_free_list(&pileB);
}

