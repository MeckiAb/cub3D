/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _get_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:55:53 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/18 15:35:04 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

int	insert_info_two(char *map_line, t_map *map, char *initials)
{
	if (!ft_strncmp(initials, "EA", 2))
	{
		map->e_text = manage_info(map_line, map, 4);
		if (!map->e_text)
			return (write(1, "Duplicated info\n", 16), 1);
	}
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

int	element_initials(char *initials)
{
	if (!ft_strncmp(initials, "NO", 3))
		return (1);
	if (!ft_strncmp(initials, "SO", 3))
		return (1);
	if (!ft_strncmp(initials, "WE", 3))
		return (1);
	if (!ft_strncmp(initials, "EA", 3))
		return (1);
	if (!ft_strncmp(initials, "F ", 3))
		return (1);
	if (!ft_strncmp(initials, "C ", 3))
		return (1);
	return (0);
}

int	get_map_info(t_map *map)
{
	int		i;
	char	*initials;
	int		j;

	i = -1;
	while (map->full_map[++i])
	{
		j = 0;
		while (map->full_map[i][j] == ' ')
			j++;
		initials = ft_substr(map->full_map[i], j, 2);
		if (element_initials(initials))
		{
			if (insert_info(map->full_map[i], map, initials))
				return (free(initials), 1);
		}
		else
		{
			free(initials);
			break ;
		}
	}
	return (0);
}
