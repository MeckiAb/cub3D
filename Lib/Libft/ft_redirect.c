/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:53:24 by jose-rig          #+#    #+#             */
/*   Updated: 2024/09/20 22:46:23 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(unsigned int n)
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

static int	ft_puthex(unsigned int n)
{
	char	*str;
	int		c;

	c = ft_count_digits(n);
	str = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthex(n / 16);
		ft_putchar(str[n % 16]);
	}
	else
		ft_putchar(str[n]);
	return (c);
}

static int	ft_puthexx(unsigned int n)
{
	char	*str;
	int		c;

	c = 0;
	c = c + ft_count_digits(n);
	str = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_puthexx(n / 16);
		ft_putchar(str[n % 16]);
	}
	else
		ft_putchar(str[n]);
	return (c);
}

int	ft_redirect(unsigned int n, char a)
{
	if (n == 0)
		return (ft_putstr("0"));
	if (a == 'X')
		return (ft_puthexx(n));
	else if (a == 'x')
		return (ft_puthex(n));
	else
		return (0);
}
