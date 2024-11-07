/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:55:53 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/07 16:01:20 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
	map->full_map = ft_split(map->map_str, '\n');
	return (0);
}

void	create_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->full_map[i])
		i++;
	map->map = (char **)ft_calloc((i - 6 + 1), sizeof(char *));
	i = 6;
	while (map->full_map[i])
	{
		map->map[i - 6] = ft_strdup(map->full_map[i]);
		i++;
	}
}

int	element_initials(char *initials)
{
	if (!ft_strncmp(initials, "NO", 2))
		return (1);
	if (!ft_strncmp(initials, "SO", 2))
		return (1);
	if (!ft_strncmp(initials, "WE", 2))
		return (1);
	if (!ft_strncmp(initials, "EA", 2))
		return (1);
	if (!ft_strncmp(initials, "F ", 2))
		return (1);
	if (!ft_strncmp(initials, "C ", 2))
		return (1);
	return (0);
}

int	get_map_info(t_map *map)
{
	int		i;
	char	*initials;

	i = -1;
	while (map->full_map[++i])
	{
		initials = ft_substr(map->full_map[i], 0, 2);
		if (element_initials(initials))
		{
			if (insert_info(map->full_map[i], map, initials))
				return (free(initials), 1);
		}
		else
			break ;
	}
	free(initials);
	return (0);
}
