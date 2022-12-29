/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_piles_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:25:16 by Hassan            #+#    #+#             */
/*   Updated: 2022/12/29 12:51:09 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(list **pileA, list **pileB, char c)
{
	list* tmp;
	
	tmp = (*pileA)->next;
	(*pileA)->next = *pileB; 
	*pileB = *pileA;
	*pileA = tmp;
	ft_printf("p%c\n", c);
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
	ft_printf("ra\n");
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
	(*pile)->next = tmp3;
	(*pile) = tmp2;
	ft_printf("sa\n");
}

void	ft_reverse_rotate(list **pile)
{
	list* tmp1;
	list* tmp2;
	list* tmp3;

	tmp1 = *pile;
	while ((*pile)->next->next != NULL)
		(*pile) = (*pile)->next;
	tmp2 = (*pile);
	tmp3 = (*pile)->next;
	(*pile) = (*pile)->next;
	(*pile)->next = tmp1;
	(*pile) = tmp2;
	(*pile)->next = NULL;
	(*pile) = tmp3;
	ft_printf("rra\n");
}

void	ft_display_list(list *ptr)
{
	list*	tmp;

	tmp = ptr;
	while(tmp != NULL)
	{
		ft_printf("%d\n", tmp->val);
		tmp = tmp->next;
	}
}