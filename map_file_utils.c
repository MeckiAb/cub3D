/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:52:36 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/07 18:54:35 by jose-rig         ###   ########.fr       */
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

int	insert_info_two(char *map_line, t_map *map, char *initials)
{
	if (!ft_strncmp(initials, "F ", 2))
	{
		map->f_color = manage_info(map_line, map, 5);
		if (!map->f_color)
			return (write(1, "Duplicated info\n", 16), 1);
	}
	if (!ft_strncmp(initials, "C ", 2))
	{
		map->c_color = manage_info(map_line, map, 6);
		if (!map->c_color)
			return (write(1, "Duplicated info\n", 16), 1);
	}
	if (!ft_strncmp(initials, "EA", 2))
	{
		map->e_text = manage_info(map_line, map, 4);
		if (!map->e_text)
			return (write(1, "Duplicated info\n", 16), 1);
	}
	return (0);
}

int	insert_info(char *map_line, t_map *map, char *initials)
{
	if (!ft_strncmp(initials, "NO", 2))
	{
		map->n_text = manage_info(map_line, map, 1);
		if (!map->n_text)
			return (write(1, "Duplicated info\n", 16), 1);
	}
	if (!ft_strncmp(initials, "SO", 2))
	{
		map->s_text = manage_info(map_line, map, 2);
		if (!map->s_text)
			return (write(1, "Duplicated info\n", 16), 1);
	}
	if (!ft_strncmp(initials, "WE", 2))
	{
		map->w_text = manage_info(map_line, map, 3);
		if (!map->w_text)
			return (write(1, "Duplicated info\n", 16), 1);
	}
	if (insert_info_two(map_line, map, initials))
		return (1);
	return (free(initials), 0);
}

int	ft_split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
