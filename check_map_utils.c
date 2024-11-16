/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:39:53 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/16 15:00:07 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	are_all_digits(const char *str)
{
	while(*str)
	{
		if (!ft_isdigit(*str))
			return(0);
		str++;
	}
	return(1);
}

int	validate_color(char *color)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(color, ',');
	while (split[i])
	{
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255
			|| ft_strlen(split[i]) == 0 || !are_all_digits(split[i]))
			return (free_split(split), 1);
		i++;
	}
	if (i != 3)
		return (free_split(split), 1);
	return (free_split(split), 0);
}

int	count_chars(char **map, char to_search)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == to_search)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	valid_map_char(char c)
{
	if (c == ' ' || c == '1' || c == '0')
		return (1);
	return (0);
}

int	start_of_map(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'))
		i--;
	while(i >= 0 && (valid_map_char(str[i])))
		i--;
	return (i);
}

int	is_there_double_nl(char *str)
{
	int	i;
	int	j;
	int	z;

	i = start_of_map(str);
	j = ft_strlen(str) - 1;
	z = 0;
	while (j > 0 && (str[j] == '\n' || str[j] == ' '))
		j--;
	while (j > i)
	{
		if (str[j] && str[j - 1] && str[j] == '\n')
		{
			if (str[j - 1] == '\n')
				return (1);
			z = j - 1;
			while (str[z - 1] && z > i && str[z] == ' ')
				z--;
			if (str[z] == '\n')
				return (1);
		}
		j--;
	}
	return (0);
}
