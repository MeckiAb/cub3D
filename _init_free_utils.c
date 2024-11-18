/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init_free_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:41:54 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/18 12:47:49 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* void	replace_spaces(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = 0;
		while (map->map[i][j] == ' ')
			j++;
		if (j > 0)
			ft_memset((void *)map->map[i], ' ', j);
	}
} */

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
