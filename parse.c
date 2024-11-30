/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:00:20 by labderra          #+#    #+#             */
/*   Updated: 2024/11/30 14:23:39 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error(char *s)
{
	while (s && *s)
		write(2, s, 1);
}

int	get_texture(char *s, t_map *map)
{}

int	get_color(char *s, t_map *map)
{}

int	get_map_info(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		valid_line;
	char	*s;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error("Fatal error\n"), 1);
	line = get_next_line(fd);
	while (line)
	{
		s = ft_strtrim(line, " \n");
		valid_line = ((!ft_strncmp(s, "NO ", 3) || !ft_strncmp(s, "SO ", 3)
			|| !ft_strncmp(s, "EA ", 3) || !ft_strncmp(s, "WE ", 3))
			&& !get_texture(s, map)) || ((!ft_strncmp(s, "C ", 2)
			|| !ft_strncmp(s, "F ", 2)) && !get_color(s, map)) || s == "";
		if (!valid_line && !ft_strncmp(s, "1", 1))
			return (free(s), free(line), close(fd), 0);
		if (!valid_line)
			return (free(s), free(line), error("Bad map\n"), close(fd), 1);
		free(line);
		free(s);
		line = get_next_line(fd);
	}
	return (close(fd), error("Missing map\n"), 1);
}

int	get_map_content(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		valid_line;
	char	*s;

	fd = open(filename, O_RDONLY);
	map->map = ft_calloc(sizeof(char *), 4096);
	if (fd < 0)
		return (error("Fatal error\n"), 1);
	line = get_next_line(fd);
	while (line)
	{
		s = ft_strtrim(line, " \n10NSEW");
		if (*s != '\0')
			return (free(s), free(line), close(fd), error("Bad Map\n"), 1);
	}
}

int	check_map_content(t_map *map)
{}

int	parse(char *filename, t_map *map)
{
	if (!ft_strnstr(filename, ".cub\0", ft_strlen(filename) + 1))
		return (error("Invalid file\n"), 1);
	if (get_map_info(filename, map))
		return (1);
	if (get_map_content(filename, map))
		return (1);
	if (check_map_content(map))
		return (1);
	return (0);
}