/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:26:36 by Hassan            #+#    #+#             */
/*   Updated: 2022/03/30 17:10:24 by hrifi-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *nb)
{
	if (!str)
	{
		*nb += write(1, "(null)", 6);
		return ;
	}
	while (*str)
	{
		*nb += write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(int n, int *nb)
{
	unsigned int	n2;
	char			tmp[10];
	int				i;

	i = 0;
	n2 = n;
	if (!n)
		*nb = *nb + write(1, "0", 1);
	if (n < 0)
	{
		*nb = *nb + write(1, "-", 1);
		n2 *= -1;
	}
	while (n2)
	{
		tmp[i++] = (n2 % 10) + 48;
		n2 = n2 / 10;
	}
	while (i--)
		*nb += write(1, &tmp[i], 1);
}

void	ft_putun(unsigned int n, int *nb)
{
	char			tmp[10];
	int				i;

	i = 0;
	if (!n)
		*nb = *nb + write(1, "0", 1);
	while (n)
	{
		tmp[i++] = (n % 10) + 48;
		n = n / 10;
	}
	while (i--)
		*nb += write(1, &tmp[i], 1);
}

void	ft_hex(unsigned long n, int *nb, int flag)
{
	char	tab_nb[100];
	char	*base;
	int		i;
	int		index;

	index = 0;
	i = 0;
	base = "0123456789abcdef";
	if (n == 0 && flag == 1)
		*nb += write(1, "0x0", 3);
	else if (!n)
		*nb += write(1, "0", 1);
	else if (flag == 1)
		*nb += write(1, "0x", 2);
	while (n)
	{
		tab_nb[i++] = n % 16;
		n /= 16;
	}
	while (--i >= 0)
	{
		index = tab_nb[i];
		*nb += write(1, &base[index], 1);
	}
}

void	ft_hex_upper(unsigned int n, int *nb)
{
	char	tab_nb[100];
	char	*base;
	int		i;
	int		index;

	index = 0;
	i = 0;
	base = "0123456789ABCDEF";
	if (!n)
		*nb += write(1, "0", 1);
	while (n)
	{
		tab_nb[i++] = n % 16;
		n /= 16;
	}
	while (--i >= 0)
	{
		index = tab_nb[i];
		*nb += write(1, &base[index], 1);
	}
}
