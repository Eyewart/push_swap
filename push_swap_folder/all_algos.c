/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_algos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:20:46 by Hassan            #+#    #+#             */
/*   Updated: 2022/12/29 13:19:53 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_shortsort(list** pileA, list** pileB)
{
	int min_index;

	min_index = ft_get_min(pileA);
	if (min_index <= ft_size_list(pileA) / 2)
	{
		while (min_index > 1)
		{
			ft_rotate(pileA);
			min_index--;
		}
		ft_push(pileA, pileB, 'b');
	}
	else if (min_index > ft_size_list(pileA) / 2)
	{
		while (min_index <= ft_size_list(pileA))
		{
			ft_reverse_rotate(pileA);
			min_index++;
		}
		ft_push(pileA, pileB, 'b');
	}
}

void	ft_algo_23(list** pile)
{
	int size;

	size = ft_size_list(pile);
	if (ft_get_max(pile) != size)
	{
		if ((*pile)->val > (*pile)->next->val)
			ft_rotate(pile);
		else
			ft_reverse_rotate(pile);
	}
	if ((*pile)->val > (*pile)->next->val)
		ft_swap(pile);
}

void	ft_radix(list **pileA, list** pileB, int nb_elements, int nb_bits)
{
	int i;
	int j;
	int mask;

	i = 0;
	mask = 1;
	while (i <= nb_bits)
	{
		j = 0;
		while (j < nb_elements)
		{
			if (((*pileA)->val & mask) == 0)
				ft_push(pileA, pileB, 'b');
			else
				ft_rotate(pileA);
			j++;
		}
		while ((*pileB) != NULL)
			ft_push(pileB, pileA, 'a');
		if (ft_is_sorted(*pileA))
			return;
		i++;
		mask *= 2;
	}
}

int		ft_get_min(list **pile)
{
	int index;
	int count;
	list* tmp;
	int min_val;

	tmp = *pile;
	min_val = tmp->val;
	count = 1;
	index = count;
	while (tmp != NULL)
	{
		if (tmp->val < min_val)
		{
			min_val = tmp->val;
			index = count;
		}
		tmp = tmp->next;
		count++;
	}
	return (index);
}

int		ft_get_max(list **pile)
{
	int count;
	int index;
	list* tmp;
	int max_val;

	tmp = *pile;
	max_val = tmp->val;
	count = 1;
	index = count;
	while (tmp != NULL)
	{
		if (tmp->val > max_val)
		{
			max_val = tmp->val;
			index = count;
		}
		tmp = tmp->next;
		count++;
	}
	return (index);
}