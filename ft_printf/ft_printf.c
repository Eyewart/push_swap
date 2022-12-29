/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:20:16 by Hassan            #+#    #+#             */
/*   Updated: 2022/03/30 16:59:25 by hrifi-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *nb)
{
	*nb += write(1, &c, 1);
}

void	do_action(char *c, va_list ap, int *nc)
{
	char	str;

	if (*c == 'c')
	{
		str = va_arg(ap, int);
		*nc = *nc + write(1, &str, 1);
	}
	else if (*c == '%')
		*nc += write(1, "%", 1);
	else if (*c == 's')
		ft_putstr(va_arg(ap, char *), nc);
	else if (*c == 'p')
		ft_hex(va_arg(ap, unsigned long), nc, 1);
	else if (*c == 'd' || *c == 'i')
		ft_putnbr(va_arg(ap, int), nc);
	else if (*c == 'u')
		ft_putun(va_arg(ap, unsigned), nc);
	else if (*c == 'x')
		ft_hex(va_arg(ap, unsigned), nc, 0);
	else if (*c == 'X')
		ft_hex_upper(va_arg(ap, unsigned), nc);
}

int	ft_printf(const char *c, ...)
{
	int		nc;
	va_list	ap;

	nc = 0;
	va_start(ap, c);
	while (*c)
	{
		if (*c == '%')
		{
			c++;
			do_action((char *)c, ap, &nc);
		}
		else
			nc = nc + write(1, c, 1);
		c++;
	}
	va_end(ap);
	return (nc);
}
