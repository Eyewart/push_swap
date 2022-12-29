/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:25:57 by Hassan            #+#    #+#             */
/*   Updated: 2022/12/29 18:21:00 by hrifi-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_list(t_list **pile, int *p_int, int N)
{
	int	i;

	i = N - 1;
	while (i >= 0)
	{
		ft_addfront(pile, p_int[i]);
		i--;
	}
}

void	ft_init_list(t_list **pile)
{
	*pile = NULL;
}

void	ft_addfront(t_list **pile, int value)
{
	t_list	*element;

	element = malloc (sizeof(t_list) * 1);
	if (!element)
		ft_exit();
	element->val = value;
	element->next = *pile;
	*pile = element;
}
