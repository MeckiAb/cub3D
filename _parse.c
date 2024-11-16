/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:42 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/16 20:25:57 by jose-rig         ###   ########.fr       */
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

char	*extract_color_info(char *str)
{
	int		i;
	int		j;
	int		count;
	char	**new;

	i = ft_strlen(str) - 1;
	count = 3;
	new = (char **)ft_calloc(sizeof(char *), 3 + 1);
	while (i >= 0 && count > 0)
	{
		while (i >= 0 && (str[i] == ' ' || str[i] == ','))
			i--;
		j = i;
		while (i >= 0 && (str[i] != ' ' && str[i] != ','))
			i--;
		new[count - 1] = ft_substr(str, i + 1, j - i);
		count --;
	}
	return (color_extraction(new));
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	printf("FULL MAP:\n");
	while (map->full_map[i])
		printf("%s\n", map->full_map[i++]);
	printf("NO:%s\n", map->n_text);
	printf("SO:%s\n", map->s_text);
	printf("EA:%s\n", map->e_text);
	printf("WE:%s\n", map->w_text);
	printf("FC:%s\n", map->f_color);
	printf("CC:%s\n", map->c_color);
	printf("MAP:\n");
	i = 0;
	while (map->map[i])
		printf("%s\n", map->map[i++]);
	printf("HEIGHT:%i\n", map->map_h);
	printf("WIDTH:%i\n", map->map_w);
	printf("PX:%f\n", map->p_x);
	printf("PY:%f\n", map->p_y);
	
}

int	check_invalids(t_map *t_map, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) == 1)
			return (1);
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_player_char(map[i][j]))
			{
				t_map->p_x = j;
				t_map->p_y = i;
				t_map->facing = map[i][j];
			}
		}
	}
	return (0);
}

int	check_map(char *file, t_map *map)
{
	if (read_map(map, file))
		return (1);
	if (get_map_info(map) || check_map_info(map))
		return (write(2, "Invalid map information\n", 24), 1);
	if (validate_color(map->c_color) || validate_color(map->f_color))
		return (write(2, "Invalid color information\n", 26), 1);
	create_map(map);
	if (validate_map(map) || check_invalids(map, map->map))
		return (write(2, "Invalid map syntax\n", 19), 1);
	return (0);
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
	replace_spaces(map);
	print_map(map);
	return (0);
}
