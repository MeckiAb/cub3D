/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check_map_ut2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:41:24 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/18 16:03:37 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
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
	while (i >= 0 && (valid_map_char(str[i])))
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

void	set_size(t_map *map)
{
	int	i;
	int	max_w;
	int	j;

	i = -1;
	max_w = 0;
	while (map->map[++i])
	{
		j = 0;
		while (map->map[i][j] && map->map[i][j] != ' '
				&& map->map[i][j] != '\t' && map->map[i][j] != '\n')
			j++;
		if (map->map[i][j] == ' ' && j > max_w)
			max_w = j;
		else if (ft_strlen(map->map[i]) > (unsigned long)max_w
			&& (map->map[i][j] != ' ' || j == 0))
			max_w = ft_strlen(map->map[i]);
	}
	map->map_h = i;
	map->map_w = max_w;
}
