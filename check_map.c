/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:53:21 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/08 14:43:48 by jose-rig         ###   ########.fr       */
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
