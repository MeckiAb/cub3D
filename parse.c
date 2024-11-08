/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:42 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/08 14:10:34 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
	if (validate_map(map))
		return (write(2, "Invalid map syntax\n", 19), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (write(2, "Invalid number of arguments\n", 28), 1);
	if (check_extension(argv[1]))
		return (write(2, "Invalid map\n", 12), 1);
	init_map(&map);
	if (check_map(argv[1], &map))
		return (free_map(&map), 1);
	print_map(&map);
	free_map(&map);
}
