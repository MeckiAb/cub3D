/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _create_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:31:14 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/18 19:36:34 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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
	map->map = (char **)ft_calloc((i - 7 + 1), sizeof(char *));
	i = 7;
	while (map->full_map[i])
	{
		if (ft_strchr(map->full_map[i], '1'))
			map->map[i - 7] = remove_spaces_end(map->full_map, i);
		i++;
	}
}
