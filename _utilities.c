/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utilities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:06:03 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/18 13:36:59 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_space(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && (str[i] != '1'))
		i--;
	return (i);
}

char	*remove_spaces_end(char **full_map, int i)
{
	return (ft_substr(full_map[i], 0, ft_space(full_map[i] - 1)));
}

int	between_walls(char *str, int j)
{
	int	i;

	i = j;
	while (str[j] && str[j] != '1')
		j++;
	while (i >= 0 && str[i] != '1')
		i--;
	if (i != -1 && str[j] == '1' && str[i] == '1')
		return (1);
	return (0);
}

char	*insert_spaces(char *line, int w)
{
	char	*new;
	int		i;

	i = -1;
	new = (char *)ft_calloc(w + 1, 1);
	while (line[++i])
		new[i] = line[i];
	while (i < w)
		new[i++] = ' ';
	free(line);
	return (new);
}

void	space_fill(char **mp, size_t w)
{
	int	i;

	i = -1;
	while (mp[++i])
	{
		if (ft_strlen(mp[i]) != w)
			mp[i] = insert_spaces(mp[i], w);
	}
}
