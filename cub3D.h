/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:59:10 by labderra          #+#    #+#             */
/*   Updated: 2024/11/07 23:14:55 by labderra         ###   ########.fr       */
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

# define IMG_WIDTH		1024
# define IMG_HEIGHT		768
# define HORIZON		576
# define PIXELS_X_UNIT	212.0
# define PI 			3.141592654
# define FOV			1.047197551
# define STEP			0.003382912

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*bg_img;
	mlx_image_t	*img;
	int			img_w;
	int			img_h;
	int			ppu;
	double		pos[2];
	double		alpha;
	double		dir[2];
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

t_game	*init_game(char *map_file);
void	generate_frame(t_game *game);


#endif
