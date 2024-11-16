/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:39:53 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/16 19:04:04 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_joinfree(char *buffer, char *aux)
{
	char	*temp;

	if (!buffer && aux)
		return (ft_strdup(aux));
	temp = ft_strjoin(buffer, aux);
	if (buffer)
		free(buffer);
	return (temp);
}

int	are_all_digits(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	validate_color(char *color)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(color, ',');
	while (split[i])
	{
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255
			|| ft_strlen(split[i]) == 0 || !are_all_digits(split[i]))
			return (free_split(split), 1);
		i++;
	}
	if (i != 3)
		return (free_split(split), 1);
	return (free_split(split), 0);
}

int	count_chars(char **map, char to_search)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == to_search)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	valid_map_char(char c)
{
	if (c == ' ' || c == '1' || c == '0'
		|| c == is_player_char(c))
		return (1);
	return (0);
}
