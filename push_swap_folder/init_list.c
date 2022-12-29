/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:25:57 by Hassan            #+#    #+#             */
/*   Updated: 2022/12/29 12:27:21 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
