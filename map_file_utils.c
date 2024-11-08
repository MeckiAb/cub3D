/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:52:36 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/08 14:41:36 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*clean_map_info(char *map_line)
{
	int	i;
	int	len;

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
	return (clean_map_info(map_line));
}

int	ft_split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
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
