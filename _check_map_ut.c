/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check_map_ut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:39:53 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/20 10:53:03 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_borders_valid(char **map)
{
	int	i;
	int	j;
	int	max_i;

	i = -1;
	max_i = ft_split_len(map);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((map[i][j] != ' ' && map[i][j] != '1' && map[i][j] != '\n')
				&& (i == 0 || i == max_i))
				return (write(1, "Player on the edge\n", 19), 1);
		}
	}
	return (0);
}

int	between_walls(char *str, int j)
{
	int	i;

	i = j;
	while (str[j] && str[j] != '1')
		j++;
	while (i >= 0 && str[i] != '1')
		i--;
	if (i != -1 && str[j] == '1' && str[i] == '1')
		return (1);
	return (0);
}

int	zero_is_incorrect(char **map, int i, int j)
{
	int	max_i;

	max_i = ft_split_len(map) - 1;
	if ((ft_strlen(map[i]) - 1) == (unsigned long)j)
		return (1);
	if (j == 0 || i == 0 || i == max_i || map[i][j - 1] == '\n'
			|| map[i][j + 1] == '\n')
		return (1);
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i - 1][j] == ' ')
	{
		if (!ft_strchr(map[i], '1') || !ft_strrchr(map[i], '1'))
			return (1);
		if (!ft_strchr(map[i - 1], '1') || !ft_strrchr(map[i - 1], '1'))
			return (1);
		if (!between_walls(map[i - 1], j))
			return (1);
	}
	if (i > 0 && ((ft_strlen(map[i - 1]) - 1 < (unsigned long)j)))
		return (1);
	return (0);
}

int	map_is_valid(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
				if (zero_is_incorrect(map, i, j))
					return (1);
			if (!valid_map_char(map[i][j]))
				return (1);
		}
	}
	return (0);
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
