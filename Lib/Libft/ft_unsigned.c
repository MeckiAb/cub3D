/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:20:51 by jose-rig          #+#    #+#             */
/*   Updated: 2024/08/02 14:42:24 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(unsigned int n)
{
	int	c;

	c = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

int	ft_put_unsigned(unsigned int n)
{
	char	*str;
	int		digits;

	str = "0123456789";
	digits = 0;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(str[n % 10]);
	}
	else
		ft_putchar(str[n]);
	digits = ft_count_digits(n);
	return (digits);
}
