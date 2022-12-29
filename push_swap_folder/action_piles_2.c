/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_piles_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:31:48 by Hassan            #+#    #+#             */
/*   Updated: 2022/12/29 16:44:11 by hrifi-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list *pile)
{
	t_list	*tmp;

	tmp = pile;
	while (tmp->next != NULL)
	{
		if (tmp->next->val != (tmp->val + 1))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_size_list(t_list **pile)
{
	int		i;
	t_list	*tmp;

	tmp = *pile;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_free_lists(t_list **pile1, t_list **pile2)
{
	ft_free_list(pile1);
	ft_free_list(pile2);
}

void	ft_free_list(t_list **pile)
{
	t_list	*tmp;

	while ((*pile) != NULL)
	{
		tmp = *pile;
		(*pile) = (*pile)->next;
		free (tmp);
	}
}
