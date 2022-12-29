/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_piles_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:31:48 by Hassan            #+#    #+#             */
/*   Updated: 2022/12/29 12:31:57 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_size_list(list** pile)
{
	int i;
	list* tmp;

	tmp = *pile;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}