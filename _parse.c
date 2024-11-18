/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:42 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/18 18:34:26 by jose-rig         ###   ########.fr       */
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

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	printf("FULL MAP:\n");
	while (map->full_map[i])
		printf("|%s|\n", map->full_map[i++]);
	printf("NO:%s\n", map->n_text);
	printf("SO:%s\n", map->s_text);
	printf("EA:%s\n", map->e_text);
	printf("WE:%s\n", map->w_text);
	printf("FC:%s\n", map->f_color);
	printf("CC:%s\n", map->c_color);
	printf("MAP:\n");
	i = 0;
	while (map->map[i])
		printf("|%s|\n", map->map[i++]);
	printf("HEIGHT:%i\n", map->map_h);
	printf("WIDTH:%i\n", map->map_w);
	printf("PX:%f\n", map->p_x);
	printf("PY:%f\n", map->p_y);
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

int	main_parse(int argc, char **argv, t_map *map)
{
	if (argc != 2)
		return (write(2, "Invalid number of arguments\n", 28), 1);
	init_map(map);
	if (check_extension(argv[1]))
		return (write(2, "Invalid map\n", 12), 1);
	if (check_map(argv[1], map))
		return (1);
	//replace_spaces(map);
	return (0);
}
