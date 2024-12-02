/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:00:20 by labderra          #+#    #+#             */
/*   Updated: 2024/12/02 22:43:11 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error(char *s)
{
	while (s && *s)
		write(2, s, 1);
}

int	get_texture(char *s, t_map *map)
{
	char **split;

	split = ft_split(s, ' ');
	if (!split)
		return (error("Fatal error\n"), 1);
	if (split[1] && !split[2])
	{
		if (!ft_strncmp(s, "NO", 2) && !map->n_text)
			map->n_text = split[1];
		if (!ft_strncmp(s, "SO", 2) && !map->s_text)
			map->s_text = split[1];
		if (!ft_strncmp(s, "EA", 2) && !map->e_text)
			map->e_text = split[1];
		if (!ft_strncmp(s, "WE", 2) && !map->w_text)
			map->w_text = split[1];
		else
			return(free_split(split), error("Duplicate texture\n"), 1);
	}
	else
		return(free_split(split), error("Wrong texture format\n"), 1);
	return (free_split(split), 0);
}

int	color_join(char *c[3], char place, t_map *map)
{
	int		i;
	char	*color;

	i = 0;
	color = ft_calloc(sizeof(char), 12);
	if (!color)
		return (free(c[0]), free(c[1]), free(c[2]), error("Fatal error\n"), 1);
	while (*c[0])
		color[i++] = *c[0]++;
	color[i++] = ',';
	while (*c[1])
		color[i++] = *c[1]++;
	color [i++] = ',';
	while (*c[2])
		color[i++] = *c[2]++;
	if (place == 'F')
		map->f_color = color;
	else
		map->c_color = color;
	return (free(c[0]), free(c[1]), free(c[2]), 0);
}

int	get_color(char *s, t_map *map)
{
	int			i;
	char		*c[3];
	char		*aux[3];

	if ((s[0] == 'F' && map->f_color) || (s[0] == 'C' && map->c_color))
		return (error("Duplicate color\n"), 1);
	if (ft_strchr(s + 1, ',') == ft_strrchr(s, ','))
		return (error("Wrong color format\n"), 1);
	aux[0] = ft_substr(s, 1, ft_strchr(s, ',') - s);
	aux[1] = ft_substr(s, ft_strchr(s, ',') - s + 1, ft_strrchr(s, ',') - s);
	aux[2] = ft_substr(s, ft_strrchr(s, ',') - s + 1, ft_strlen(s));
	i = 0;
	while (i < 3)
	{
		c[i] = ft_trim(aux[0], ' ');
		free(aux[i]);
		aux[i] = ft_itoa(ft_atoi(c[i]));
		if (ft_strncmp(c[i], aux[i], ft_strlen(c[i]))
				|| ft_atoi(c[i]) < 0 || ft_atoi(c[i]) > 255)
			return (error("Wrong color format\n"), 1);
		free(aux[i++]);
	}
	return (color_join(c, s[0], map));
}

int	get_full_map(char *filename, t_map *map)
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
			return (free(s), get_map_content(fd, map, line));
		if (!valid_line)
			return (free(s), free(line), error("Bad map\n"), close(fd), 1);
		free(line);
		free(s);
		line = get_next_line(fd);
	}
	return (close(fd), error("Missing map\n"), 1);
}

int	get_map_content(int fd, t_map *map, char *line)
{
	char	*s;
	int		i;

	i = 0;
	map->map = ft_calloc(sizeof(char *), 4096);
	while (line)
	{
		s = ft_strtrim(line, " \n10NSEW");
		if (*s != '\0')
			return (free(s), free(line), close(fd), error("Bad Map\n"), 1);
		map->map[i++] = line;
		free(line);
		free(s);
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}

int	check_map_content(t_map *map)
{}

int	parse(char *filename, t_map *map)
{
	if (!ft_strnstr(filename, ".cub\0", ft_strlen(filename) + 1))
		return (error("Invalid file\n"), 1);
	if (get_full_map(filename, map))
		return (1);
	if (check_map_content(map))
		return (1);
	return (0);
}