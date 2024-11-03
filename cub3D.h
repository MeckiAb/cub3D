/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:59:10 by labderra          #+#    #+#             */
/*   Updated: 2024/11/03 22:31:30 by labderra         ###   ########.fr       */
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
# include "MLX42/include/MLX42/MLX42.h"

# define IMG_WIDTH		640
# define IMG_HEIGHT		480
# define PIXELS_X_UNIT	128
# define WALL			0
# define NOT_WALL		1
# define N_ENTRY		10
# define E_ENTRY		11
# define S_ENTRY		12
# define W_ENTRY		13


typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*bg_img;
	mlx_image_t	*img;
	int			img_w;
	int			img_h;
	int			ppu;
	double		x_pos;
	double 		y_pos;
	double		x_dir;
	double		y_dir;
	double		alpha;
	double		fov;
	mlx_image_t	*n_texture;
	mlx_image_t	*e_texture;
	mlx_image_t	*s_texture;
	mlx_image_t	*w_texture;
	uint32_t	ceiling;
	uint32_t	floor;
	int			map_w;
	int			map_h;
	char		**map;
}	t_game;

#endif