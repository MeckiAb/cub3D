/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_puntero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:22:29 by jose-rig          #+#    #+#             */
/*   Updated: 2024/08/02 14:42:41 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(unsigned long long n)
{
	int	c;

	c = 1;
	while (n / 16 != 0)
	{
		n = n / 16;
		c++;
	}
	return (c);
}

static int	ft_print_void(unsigned long long n)
{
	char	*str;
	int		c;

	c = ft_count_digits(n);
	str = "0123456789abcdef";
	if (n >= 16)
	{
		ft_print_void(n / 16);
		ft_putchar(str[n % 16]);
	}
	else
		ft_putchar(str[n]);
	return (c);
}

int	ft_put_puntero(unsigned long long n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	digit = ft_print_void(n) + 2;
	return (digit);
}
