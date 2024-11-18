/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:53:21 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/18 12:09:22 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	zero_is_incorrect(char **map, int i, int j)
{
	int	max_i;

	max_i = ft_split_len(map) - 1;
	if ((ft_strlen(map[i]) - 1) == (unsigned long)j)//ultima posicion
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
	int	max_i;

	i = -1;
	max_i = ft_split_len(map);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
				if (zero_is_incorrect(map, i, j))
					return (1);
		}
	}
	return (0);
}

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

int	validate_map(t_map *map)
{
	char	*str;
	int		count;
	int		missing_count;

	str = "NSEW";
	missing_count = 0;
	count = 0;
	while (*str)
	{
		count += count_chars(map->map, *str);
		if (count > 1)
			return (write(2, "Too many players: ", 18), 1);
		if (count == 0)
			missing_count++;
		str++;
	}
	if (missing_count == 4)
		return (write(2, "Missing player: ", 16), 1);
	if (is_there_double_nl(map->map_str))
		return (write(2, "Map is separated by newline: ", 29), 1);
	if (map_is_valid(map->map) || map_borders_valid(map->map))
		return (write(2, "Map is invalid: ", 16), 1);
	set_size(map);
	return (0);
}
