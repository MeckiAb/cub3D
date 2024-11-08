/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:55:53 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/08 14:26:14 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
