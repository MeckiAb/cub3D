/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:15:50 by labderra          #+#    #+#             */
/*   Updated: 2024/11/18 11:36:05 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	collision(t_game *game, double ph[2], double ray[2])
{
	if (ph[0] < 1.0 || ph[0] > game->map_h - 1
		|| ph[1] < 1.0 || ph[1] > game->map_w - 1)
		return (1);
	//printf("[H:%i W:%i][pos0:%f p1:%f] [%c][alpha:%f]\n",game->map_h , game->map_w, game->pos[0], game->pos[1], game->t_map->facing, game->alpha);
	if (ph[0] == ceil(ph[0]))
		return (game->map[(int)ph[0] - (ray[0] < 0)][(int)ph[1]] == '1');
	else
		return (game->map[(int)ph[0]][(int)ph[1] - (ray[1] < 0)] == '1');
}

int	next_point(t_game *game, double photon[2], double m[2], double ray[2])
{
	double	option_1[2];
	double	option_2[2];
	//char	map_pos;

	option_1[0] = ceil(photon[0]) - (ray[0] < 0)
		+ (ray[0] > 0) * (ceil(photon[0]) == photon[0]);
	option_1[1] = photon[1] + m[0] * (option_1[0] - photon[0]);
	option_2[1] = ceil(photon[1]) - (ray[1] < 0)
		+ (ray[1] > 0) * (ceil(photon[1]) == photon[1]);
	option_2[0] = photon[0] + m[1] * (option_2[1] - photon[1]);
	if (fabs(option_1[0] - photon[0]) < fabs(option_2[0] - photon[0]))
	{
		//printf("IFp[0]:%f p[1]:%f\nop1[0]:%f op1[1]:%f\n", photon[0], photon[1], option_1[0], option_1[1]);
		photon[0] = option_1[0];
		photon[1] = option_1[1];
	}
	else
	{
		//printf("ELSEp[0]:%f p1[1]:%f\nop2[0]:%f op2[1]:%f\n", photon[0], photon[1], option_2[0], option_2[1]);
		photon[0] = option_2[0];
		photon[1] = option_2[1];
	}
	return (collision(game, photon, ray));
}

uint32_t	endian_switch(uint32_t color)
{
	return ((color & 0x000000ff) << 24 | (color & 0x0000ff00) << 8
		| (color & 0x00ff0000) >> 8 | (color & 0xff000000) >> 24); 
}

void	generate_column(t_game *game, double scale, int column_id, double x_coord)
{
	int			i;
	int			start;
	int			end;
	uint32_t	color;

	i = 0;
	start = (game->img_h - scale * 2 * TEXTURE_S) / 2;
	end = (game->img_h + scale * 2 * TEXTURE_S) / 2;
	while (i < start)
		mlx_put_pixel(game->img, column_id, i++, game->ceiling);
	while (i < end && i < game->img_h)
	{
		ft_memcpy(&color, game->current_texture->pixels + 
			(4 * (int)(TEXTURE_S * x_coord)
			+ (4 * TEXTURE_S * (int)((i - start) / (2 * scale)))), 4);
		mlx_put_pixel(game->img, column_id, i, endian_switch(color));
		i++;
	}
	while (i < game->img_h)
		mlx_put_pixel(game->img, column_id, i++, game->floor);
}

double	generate_x_coord(t_game *game, double photon[2], double ray[2])
{
	double	x_coord;

	if (photon[0] == ceil(photon[0]) && ray[0] > 0.0)
	{
		game->current_texture = game->w_texture;
		x_coord = photon[1] - floor(photon[1]);
	}
	else if (photon[0] == ceil(photon[0]) && ray[0] < 0.0)
	{
		game->current_texture = game->e_texture;
		x_coord = photon[1] - ceil(photon[1]);
	}
	else if (ray[1] > 0.0)
	{
		game->current_texture = game->s_texture;
		x_coord = photon[0] - floor(photon[0]);
	}
	else
	{
		game->current_texture = game->n_texture;
		x_coord = photon[0] - ceil(photon[0]);
	}
	return (x_coord);
	
}

void	generate_frame(t_game *game)
{
	int		i;
	double	ray[2];
	double	photon[2];
	double	scale;
	double	m[2];
	
	i = 0;
	while (i < game->img_w)
	{
		ray[0] = game->dir[0] - game->dir[1] * (512 - i) * STEP;
		ray[1] = game->dir[1] + game->dir[0] * (512 - i) * STEP;
		//printf("r[0]:%f r[1]:%f\n", ray[0], ray[1]);
		photon[0] = game->pos[0];
		photon[1] = game->pos[1];
		m[0] = ray[1] / ray[0];
		m[1] = ray[0] / ray[1];
		while (!next_point(game, photon, m, ray))
			continue ;
		scale = 1 / (cos(STEP * (512 - i))
			* (hypot(photon[0] - game->pos[0], photon[1] - game->pos[1])));
		generate_column(game, scale, i, generate_x_coord(game, photon, ray));
		++i;
	}
}

