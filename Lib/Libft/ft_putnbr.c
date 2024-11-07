/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:23:57 by jose-rig          #+#    #+#             */
/*   Updated: 2024/08/02 14:42:33 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	c;

	c = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

static int	ft_print_putnbr(int n)
{
	char		*str;
	int			digits;
	int			nsign;
	long int	nbr;

	nbr = n;
	str = "0123456789";
	digits = 0;
	nsign = nbr;
	if (nsign < 0)
	{
		ft_putchar('-');
		nbr *= -1;
		digits++;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(str[nbr % 10]);
	}
	else
		ft_putchar(str[nbr]);
	digits = digits + ft_count_digits(nbr);
	return (digits);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else
		return (ft_print_putnbr(n));
}
