/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:59:10 by labderra          #+#    #+#             */
/*   Updated: 2024/11/16 19:00:54 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <math.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# define IMG_WIDTH		1024
# define IMG_HEIGHT		768
# define HORIZON		576
# define TEXTURE_S		212
# define PI 			3.141592654
# define FOV			0.785398163
// STEP = tg(FOV) / IMG_WIDTH
//# define STEP			0.001691456			// 60 deg
//# define STEP			0.001520906			// 1 rad
# define STEP			0.000976562			// 45 deg

typedef struct c_map
{
	char		**full_map;
	char		*map_str;
	char		*n_text;
	char		*s_text;
	char		*e_text;
	char		*w_text;
	char		*f_color;
	char		*c_color;
	char		**map;
	int			map_h;
	int			map_w;
	double		p_x;
	double		p_y;
}	t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				img_w;
	int				img_h;
	int				ppu;
	double			pos[2];
	double			alpha;
	double			dir[2];
	mlx_texture_t	*n_texture;
	mlx_texture_t	*e_texture;
	mlx_texture_t	*s_texture;
	mlx_texture_t	*w_texture;
	mlx_texture_t	*current_texture;
	uint32_t		ceiling;
	uint32_t		floor;
	int				map_w;
	int				map_h;
	char			**map;
	struct c_map	*t_map;
}	t_game;

t_game	*init_game(t_map *t_map);
void	calculate_directions(t_game *game, double d_alpha);
void	check_movement(t_game *game, double move);
void	generate_frame(t_game *game);
void	free_all(t_game *game);
//
char	*ft_joinfree(char *buffer, char *aux);
int		main_parse(int argc, char **argv, t_map *map);
void	print_map(t_map *map);
int		check_map(char *file, t_map *map);

//parse 
char	*color_extraction(char **new);
char	*extract_color_info(char *str);
//checkmap utils
int		start_of_map(char *str);
int		validate_color(char *color);
int		count_chars(char **map, char to_search);
int		valid_map_char(char c);
int		is_there_double_nl(char *str);
int		is_player_char(char p);
//mapfile utils
char	*clean_map_info(char *map_line, int type);
char	*manage_info(char *map_line, t_map *map, int type);
int		ft_split_len(char **split);
int		read_map(t_map *map, char *file);
void	create_map(t_map *map);
//checkmap
int		invalid_space(char **map, int i);
int		check_extension(char *str);
int		validate_map(t_map *map);
int		map_borders_valid(char **map);
int		check_map(char *file, t_map *map);
void	set_size(t_map *map);
//check_map_info
int		check_map_info(t_map *map);
int		insert_info(char *map_line, t_map *map, char *initials);
int		insert_info_two(char *map_line, t_map *map, char *initials);
int		element_initials(char *initials);
int		get_map_info(t_map *map);
//inits and frees
void	replace_spaces(t_map *map);
void	init_map(t_map *map);
void	free_map(t_map *map);
void	free_split(char **split);


#endif
