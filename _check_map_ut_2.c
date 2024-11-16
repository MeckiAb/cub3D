/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check_map_ut_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:41:24 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/16 17:31:15 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_player_char(char p)
{
	if (p == 'N' || p == 'S' || p == 'E' || p == 'W')
		return (1);
	return (0);
}

int	ft_split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	check_extension(char *str)
{
	int		i;
	int		len;
	char	*temp;

	temp = NULL;
	if (!str || !str[0])
		return (1);
	len = ft_strlen(str) - 1;
	i = len;
	while (i > 0 && str[i] != '.')
		i--;
	if (len - i != 3 || i == 0)
		return (1);
	temp = ft_substr(str, i, 4);
	if (ft_strncmp(temp, ".cub", 4))
		return (free(temp), 1);
	i = -1;
	len = 0;
	while (str[++i])
		if (str[i] == '.')
			len++;
	if (len != 1)
		return (free(temp), 1);
	return (free(temp), 0);
}

int	start_of_map(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'))
		i--;
	while(i >= 0 && (valid_map_char(str[i])))
		i--;
	return (i);
}

int	is_there_double_nl(char *str)
{
	int	i;
	int	j;
	int	z;

	i = start_of_map(str);
	j = ft_strlen(str) - 1;
	z = 0;
	while (j > 0 && (str[j] == '\n' || str[j] == ' '))
		j--;
	while (j > i)
	{
		if (str[j] && str[j - 1] && str[j] == '\n')
		{
			if (str[j - 1] == '\n')
				return (1);
			z = j - 1;
			while (str[z - 1] && z > i && str[z] == ' ')
				z--;
			if (str[z] == '\n')
				return (1);
		}
		j--;
	}
	return (0);
}
