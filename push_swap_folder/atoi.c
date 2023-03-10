/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:58:42 by Hassan            #+#    #+#             */
/*   Updated: 2022/12/29 16:10:26 by hrifi-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	ft_exit(void)
{
	char	*str;

	str = "Error\n";
	write(2, str, ft_strlen(str));
	exit(1);
}

static long	int	get_result(const char *str, int sign)
{
	long int	result;
	int			j;

	j = 0;
	result = 0;
	while (ft_isdigit(str[j]))
		result = 10 * result + (str[j++] - '0');
	if ((sign == 1 && result > 2147483647)
		|| (sign == -1 && result > 2147483648))
		ft_exit();
	if (str[j] != 0)
		ft_exit();
	return ((int)result * sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		sign *= -1;
		i++;
	}
	return (get_result((&str[i]), sign));
}
