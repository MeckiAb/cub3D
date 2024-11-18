/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _create_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:31:14 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/18 16:49:36 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*remove_spaces_end(char **full_map, int i)
{
	return (ft_substr(full_map[i], 0, ft_space_purge(full_map[i]) + 1));
}

int	ft_space_purge(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && (str[i] != '1'))
		i--;
	return (i);
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
		if (ft_strchr(map->full_map[i], '1'))
			map->map[i - 6] = remove_spaces_end(map->full_map, i);
		i++;
	}
}
