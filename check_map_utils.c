/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:39:53 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/07 18:55:10 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	validate_color(char *color)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(color, ',');
	while (split[i])
	{
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
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

	i = 0;
	while (str[i])
	{
		if (str[i + 1] && str[i] == '\n' && valid_map_char(str[i + 1]))
		{
			i++;
			break ;
		}
		i++;
	}
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
