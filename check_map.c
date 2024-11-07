/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:53:21 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/07 18:55:27 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_extension(char *str)
{
	int		i;
	int		len;
	char	*temp;

	temp = NULL;
	if (!str || !str[0])
		return (1);
	len = ft_strlen(str) - 1;
	i = len;
	while (str[i] != '.')
		i--;
	if (len - i != 3)
		return (1);
	temp = ft_substr(str, i, 4);
	if (ft_strncmp(temp, ".cub", 4))
		return (free(temp), 1);
	i = -1;
	len = 0;
	while (str[++i])
		if (str[i] == '.')
			len++;
	if (len != 1)
		return (free(temp), 1);
	return (free(temp), 0);
}

int	check_map_info(t_map *map)
{
	if (!map->n_text)
		return (write(1, "Missing NORTH texture\n", 22), 1);
	if (!map->s_text)
		return (write(1, "Missing SOUTH texture\n", 22), 1);
	if (!map->e_text)
		return (write(1, "Missing EAST texture\n", 21), 1);
	if (!map->w_text)
		return (write(1, "Missing WEST texture\n", 21), 1);
	if (!map->f_color)
		return (write(1, "Missing Floor color\n", 21), 1);
	if (!map->c_color)
		return (write(1, "Missing Ceiling color\n", 23), 1);
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
			{
				if (j == 0 || i == 0 || i == max_i || map[i][j - 1] == ' '
					|| map[i][j + 1] == ' ' || map[i][j - 1] == '\n'
						|| map[i][j + 1] == '\n')
					return (1);
				if (i > 0 && ((ft_strlen(map[i - 1]) - 1 < (unsigned long)j)
						|| map[i - 1][j] == ' '))
					return (1);
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
			return (write(2, "Too many players: ", 17), 1);
		if (count == 0)
			missing_count++;
		str++;
	}
	if (missing_count == 4)
		return (write(2, "Missing player: ", 16), 1);
	if (is_there_double_nl(map->map_str))
		return (write(2, "Map is separated by newline: ", 29), 1);
	if (map_is_valid(map->map))
		return (write(2, "Map is invalid: ", 16), 1);
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
	if (validate_map(map))
		return (write(2, "Invalid map syntax\n", 19), 1);
	return (0);
}
