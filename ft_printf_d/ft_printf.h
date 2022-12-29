/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:36:03 by Hassan            #+#    #+#             */
/*   Updated: 2022/03/30 17:03:31 by hrifi-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *c, ...);
void	do_action(char *c, va_list ap, int *nc);
void	ft_putchar(char c, int *nb);
void	ft_putstr(char *str, int *nb);
void	ft_putnbr(int n, int *nb);
void	ft_putun(unsigned int n, int *nb);
void	ft_hex(unsigned long n, int *nb, int flag);
void	ft_hex_upper(unsigned int n, int *nb);

#endif
