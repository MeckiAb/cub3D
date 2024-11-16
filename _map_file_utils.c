/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:52:36 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/16 18:30:52 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*clean_map_info(char *map_line, int type)
{
	int	i;
	int	len;

	if (type > 4)
		return (extract_color_info(map_line));
	len = ft_strlen(map_line) - 1;
	i = len;
	while (map_line[i - 1] != ' ')
		i--;
	return (ft_substr(map_line, i, len - i + 1));
}

char	*manage_info(char *map_line, t_map *map, int type)
{
	char	*element;

	if (type == 1)
		element = map->n_text;
	if (type == 2)
		element = map->s_text;
	if (type == 3)
		element = map->w_text;
	if (type == 4)
		element = map->e_text;
	if (type == 5)
		element = map->f_color;
	if (type == 6)
		element = map->c_color;
	if (element)
		return (free(element), NULL);
	return (clean_map_info(map_line, type));
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

int	ft_space(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while(i >= 0 && (str[i] != '1'))
		i--;
	return (i);
}

void	create_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->full_map[i])
		i++;
	map->map = (char **)ft_calloc((i - 6 + 1), sizeof(char *));
	i = 6;
	while (map->full_map[i])
	{
		j = 0;
		if (ft_strchr(map->full_map[i], '1'))
			map->map[i - 6] = ft_substr(map->full_map[i], 0, ft_space(map->full_map[i] - 1));
		i++;
	}
}
