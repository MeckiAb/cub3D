/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init_free_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:32:05 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/19 18:36:12 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_map(t_map *map)
{
	map->full_map = NULL;
	map->map_str = NULL;
	map->n_text = NULL;
	map->s_text = NULL;
	map->e_text = NULL;
	map->w_text = NULL;
	map->f_color = NULL;
	map->c_color = NULL;
	map->d_text = NULL;
	map->map = NULL;
	map->map_h = 0;
	map->map_w = 0;
	map->p_x = 0;
	map->p_y = 0;
}

void	free_map(t_map *map)
{
	if (map->full_map)
		free_split(map->full_map);
	if (map->map)
		free_split(map->map);
	if (map->map_str)
		free(map->map_str);
	if (map->n_text)
		free(map->n_text);
	if (map->s_text)
		free(map->s_text);
	if (map->e_text)
		free(map->e_text);
	if (map->w_text)
		free(map->w_text);
	if (map->f_color)
		free(map->f_color);
	if (map->c_color)
		free(map->c_color);
	if (map->d_text)
		free(map->d_text);
}

void	free_split(char **split)
{
	size_t	i;

	if (split)
	{
		i = -1;
		while (split[++i])
			free(split[i]);
		free(split);
	}
}

void	free_split_calloc(char **split, int size)
{
	int	i;

	if (split)
	{
		i = 0;
		while (i < size)
			free(split[i++]);
		free(split);
	}
}
