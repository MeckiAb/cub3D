/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:42 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/19 18:57:53 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

int	main_parse(int argc, char **argv, t_map *map)
{
	if (argc != 2)
		return (write(2, "Invalid number of arguments\n", 28), 1);
	init_map(map);
	if (check_extension(argv[1]))
		return (write(2, "Invalid map\n", 12), 1);
	if (check_map(argv[1], map))
		return (1);
	return (0);
}
