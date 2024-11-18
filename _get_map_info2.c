/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _get_map_info2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:52:36 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/18 17:57:06 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*color_extraction(char **new)
{
	char	*res;
	int		i;

	res = NULL;
	i = -1;
	while (new[++i])
	{
		res = ft_joinfree(res, new[i]);
		if (new[i + 1])
			res = ft_joinfree(res, ",");
	}
	return (free_split(new), res);
}

char	*extract_color_info(char *str, int count, int i, int j)
{
	char	**new;

	new = (char **)ft_calloc(sizeof(char *), 3 + 1);
	while (i >= 0 && count >= 0)
	{
		while (i >= 0 && (str[i] == ' ' || str[i] == ','))
		{
			if (i > 0 && str[i] == ',' && str[i - 1] == ',')
				return (free_split_calloc(new, 3), NULL);
			if (i > 0 && str[i] == ',')
			{
				i--;
				while (i > 0 && str[i] == ' ')
					i--;
				if (str[i] == ',')
					return (free_split_calloc(new, 3), NULL);
			}
			i--;
		}
		j = i;
		while (i >= 0 && (str[i] != ' ' && str[i] != ','))
			i--;
		new[count--] = ft_substr(str, i + 1, j - i + 1);
	}
	return (color_extraction(new));
}

char	*clean_map_info(char *map_line, int type)
{
	int	i;
	int	len;

	if (type > 4)
		return (extract_color_info(map_line, 2, ft_strlen(map_line) - 1, 0));
	len = ft_strlen(map_line) - 1;
	i = len;
	while (map_line[i - 1] != ' ')
		i--;
	return (ft_substr(map_line, i, len - i + 1));
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
		return (write(1, "Missing Floor color\n", 20), 1);
	if (!map->c_color)
		return (write(1, "Missing Ceiling color\n", 22), 1);
	return (0);
}
