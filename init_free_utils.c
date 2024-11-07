/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:41:54 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/07 16:04:15 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
}

void	free_map(t_map *map)
{
	free_split(map->full_map);
	free_split(map->map);
	free(map->map_str);
	free(map->n_text);
	free(map->s_text);
	free(map->e_text);
	free(map->w_text);
	free(map->f_color);
	free(map->c_color);
}

void	free_split(char **split)
{
	size_t	i;

	if (split)
	{
		i = 0;
		while (split[i])
			free(split[i++]);
		free(split);
	}
}
