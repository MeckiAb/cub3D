/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:59:10 by labderra          #+#    #+#             */
/*   Updated: 2024/11/18 16:29:36 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
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
	int32_t			cursor_x;
	int32_t			cursor_y;
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
}	t_game;

t_game	*init_game(char *map_file);
void	calculate_directions(t_game *game, double d_alpha);
void	check_movement(t_game *game, double move);
void	check_strife(t_game *game, double move);
void	generate_frame(t_game *game);
void	free_all(t_game *game);



#endif
