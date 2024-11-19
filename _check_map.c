/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:53:21 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/19 18:35:14 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_invalids(t_map *t_map, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) == 1)
			return (1);
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_player_char(map[i][j]))
			{
				t_map->p_x = j;
				t_map->p_y = i;
				t_map->facing = map[i][j];
			}
		}
	}
	return (0);
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

int	read_map(t_map *map, char *file)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (write(2, "Failed to open map\n", 19), 1);
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		map->map_str = ft_joinfree(map->map_str, line);
	}
	if (!map->map_str || !ft_strlen(map->map_str))
		return (write(2, "Map is empty\n", 13), 1);
	map->full_map = ft_split(map->map_str, '\n');
	return (0);
}

int	check_map(char *file, t_map *map)
{
	if (read_map(map, file))
		return (1);
	if (get_map_info(map) || check_map_info(map))
		return (write(2, "Invalid map information\n", 24), 1);
	if (validate_color(map->c_color) || validate_color(map->f_color))
		return (write(2, "Invalid color information\n", 26), 1);
	create_map(map);
	if (validate_map(map) || check_invalids(map, map->map))
		return (write(2, "Invalid map syntax\n", 19), 1);
	space_fill(map->map, map->map_w);
	return (0);
}
