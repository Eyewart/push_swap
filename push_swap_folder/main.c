/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:00:42 by hrifi-la          #+#    #+#             */
/*   Updated: 2022/12/29 18:27:00 by hrifi-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_duplicate(int *list_int, int size)
{
	int	i;
	int	j;

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

unsigned int	ft_count_bits(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n >>= 1;
	}
	return (count);
}

int	*ft_sort_indexes(int *sorted_tab, int *saved_tab, int size)
{
	int	*tab_with_indexes;
	int	i;
	int	j;

	tab_with_indexes = malloc(sizeof(int) * size);
	i = 0;
	if (!tab_with_indexes)
		ft_exit();
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (saved_tab[i] == sorted_tab[j])
			{
				tab_with_indexes[i] = j;
				break ;
			}
			j++;
		}		
		i++;
	}
	return (tab_with_indexes);
}

void	ft_decision_3(t_list **pileA, t_list **pileB, int nb_elements)
{
	if (nb_elements <= 1 || ft_is_sorted(*pileA))
		return ;
	while (ft_size_list(pileA) > 3)
		ft_shortsort(pileA, pileB);
	ft_algo_23(pileA);
	while ((*pileB) != NULL)
		ft_push(pileB, pileA, 'a');
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;
	int		*tab_of_int;
	int		*save_tab;
	int		*absolute_tab;

	ft_init_list(&pile_a);
	tab_of_int = ft_make_tab(argc - 1, &argv[1]);
	if (ft_is_duplicate(tab_of_int, argc - 1))
		ft_exit();
	save_tab = ft_copy_tab(tab_of_int, argc - 1);
	ft_bubblesort(&tab_of_int, argc - 1);
	absolute_tab = ft_sort_indexes(tab_of_int, save_tab, argc - 1);
	free(save_tab);
	free(tab_of_int);
	ft_fill_list(&pile_a, absolute_tab, argc - 1);
	free(absolute_tab);
	ft_init_list(&pile_b);
	if (argc - 1 < 20)
		ft_decision_3(&pile_a, &pile_b, argc - 1);
	else if (!ft_is_sorted(pile_a))
		ft_radix(&pile_a, &pile_b, argc - 1, ft_count_bits (argc - 1));
	ft_free_lists(&pile_a, &pile_b);
}
