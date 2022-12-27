/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:00:42 by hrifi-la          #+#    #+#             */
/*   Updated: 2022/12/28 00:37:39 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

/*
STILL TO DO:
ft_is_duplicate - OK
bubble_sort - OK
store indexes in initial array - OK
read array from N while addfront - OK
create functions push, rotate, etc.. - OK
implement radix / binary sort - OK
check the particular cases (create main to test)
ft_printf
protect malloc
no memory leaks
valgrind
*/

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

void	ft_bubblesort(int** list_int, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			//printf("%d\n", list_int[0][i]);
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

int*	ft_copy_tab(int* list_int, int size) // before bubblesorting
{
	int i;
	int* new_list_int;

	i = 0;
	new_list_int = malloc(sizeof(int) * size);
	if(!new_list_int)
		return (NULL);
	while (i < size)
	{
		new_list_int[i] = list_int[i];
		i++;
	}
	return (new_list_int);
}

void	ft_push(list **pileA, list **pileB, char c)
{
	list* tmp;
	
	tmp = (*pileA)->next;
	(*pileA)->next = *pileB; 
	*pileB = *pileA;
	*pileA = tmp;
	printf("p%c\n", c);
}

void	ft_rotate(list **pile)
{
	list* tmp1;
	list* tmp2;

	tmp1 = *pile;
	tmp2 = (*pile)->next;
	while ((*pile)->next != NULL)
		(*pile) = (*pile)->next;
	(*pile)->next = tmp1;
	(*pile) = (*pile)->next;
	(*pile)->next = NULL;
	*pile = tmp2;
	printf("ra\n");
}

void	ft_swap(list **pile)
{
	list *tmp1;
	list *tmp2;
	list *tmp3;

	tmp1 = *pile;
	tmp2 = (*pile)->next;
	*pile = (*pile)->next;
	tmp3 = (*pile)->next;
	(*pile)->next = tmp1;
	(*pile) = (*pile)->next;
	(*pile)->next = tmp2;
	(*pile) = tmp2;
	printf("sa\n");
}

void	ft_reverse_rotate(list **pile)
{
	list* tmp1;
	list* tmp2;

	tmp1 = *pile;
	while ((*pile)->next->next != NULL)
		(*pile) = (*pile)->next;
	tmp2 = (*pile);
	(*pile) = (*pile)->next;
	(*pile)->next = tmp1;
	(*pile) = tmp2;
	(*pile)->next = NULL;
	printf("rra\n");
}

void	ft_addfront(list **pile, int value)
{
	list *element;

	element = malloc (sizeof(list) * 1);
	if(!element)
		return;
	element->val = value;
	element->next = *pile;
	*pile = element;
}

void	ft_fill_list(list **pile, int *p_int, int N)
{
	int i;

	i = N - 1;
	while (i >= 0)
	{
		ft_addfront(pile, p_int[i]);
		i--;
	}
}

void	ft_init_list (list** pile)
{
	*pile = malloc (sizeof(list) * 1);
	*pile = NULL;
}

int*	ft_make_tab(int N, char **arg)
{
	int*	tab;
	int		i;

	tab = malloc (sizeof(int) * N);
	if(!tab)
		return (NULL);
	i = 0;
	while (i < N)
	{
		tab[i] = ft_atoi(arg[i]);
		i++;
	}
	return (tab);
}

void	ft_display_list(list *ptr)
{
	list*	tmp;

	tmp = ptr;
	while(tmp != NULL)
	{
		printf("%d\n", tmp->val);
		tmp = tmp->next;
	}
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

int	ft_is_sorted(list* pile)
{
	list* tmp;

	tmp = pile;
	while (tmp->next != NULL)
	{
		if (tmp->next->val != (tmp->val + 1))
			return (0);
		tmp = tmp->next;
	}
	return (1);
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

void	ft_shortsort(list **pileA, list** pileB, int nb_elements)
{
	if (nb_elements == 1)
		return;
	if (nb_elements == 2)
	{
		if ((*pileA)->val > (*pileA)->next->val)
			ft_rotate(pileA);	
	}
	if (nb_elements == 3)
	{
		if ((*pileA)->val > (*pileA)->next->val)
			ft_rotate(pileA);
				if ((*pileA)->val > (*pileA)->next->val)
					ft_rotate(pileA);
		else
			ft_push(pileA, pileB, 'b');
	}
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
	save_tab = ft_copy_tab(tab_of_int, argc - 1);
	ft_bubblesort(&tab_of_int, argc - 1);
	absolute_tab = ft_sort_indexes(tab_of_int, save_tab, argc - 1);
	ft_fill_list(&pileA, absolute_tab, argc - 1);
	nb_bits = ft_count_bits (argc - 1);
	ft_init_list(&pileB);
	ft_radix(&pileA, &pileB, argc - 1, nb_bits);
}

