/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:41:51 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/07 18:55:31 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <unistd.h>
# include <stdio.h>
# include "Lib/Libft/libft.h"

typedef struct c_map
{
	char	**full_map;
	char	*map_str;
	char	*n_text;
	char	*s_text;
	char	*e_text;
	char	*w_text;
	char	*f_color;
	char	*c_color;
	char	**map;
}	t_map;

//checkmap utils
int		validate_color(char *color);
int		count_chars(char **map, char to_search);
int		valid_map_char(char c);
int		start_of_map(char *str);
int		is_there_double_nl(char *str);
//mapfile utils
char	*clean_map_info(char *map_line);
int		insert_info(char *map_line, t_map *map, char *initials);
int		insert_info_two(char *map_line, t_map *map, char *initials);
int		ft_split_len(char **split);
//checkmap
int		check_extension(char *str);
int		check_map_info(t_map *map);
int		validate_map(t_map *map);
int		check_map(char *file, t_map *map);
//mapstruct
int		read_map(t_map *map, char *file);
void	create_map(t_map *map);
int		get_map_info(t_map *map);
//inits and frees
void	init_map(t_map *map);
void	free_map(t_map *map);
void	free_split(char **split);
#endif