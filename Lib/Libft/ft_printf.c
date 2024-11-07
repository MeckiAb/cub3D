/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:03:07 by jose-rig          #+#    #+#             */
/*   Updated: 2024/08/02 14:42:02 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char a, va_list arg)
{
	if (a == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (a == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (a == 'i' || a == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	if (a == 'x' || a == 'X')
		return (ft_redirect(va_arg(arg, unsigned int), a));
	if (a == 'p')
		return (ft_put_puntero(va_arg(arg, unsigned long long)));
	if (a == '%')
		return (ft_putchar('%'));
	if (a == 'u')
		return (ft_put_unsigned(va_arg(arg, unsigned int)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		c;

	i = 0;
	c = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			c = c + ft_check(str[i + 1], arg);
			i += 2;
		}
		else if (str[i] != '\0')
		{
			write(1, &str[i++], 1);
			c++;
		}
	}
	va_end(arg);
	return (c);
}
