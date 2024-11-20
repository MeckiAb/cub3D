/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utilities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:06:03 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/20 11:46:55 by jose-rig         ###   ########.fr       */
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
	while (mp && mp[++i])
	{
		if (ft_strlen(mp[i]) != w)
			mp[i] = insert_spaces(mp[i], w);
	}
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

int	ft_split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
