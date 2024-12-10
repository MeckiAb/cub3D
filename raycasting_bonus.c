/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:15:50 by labderra          #+#    #+#             */
/*   Updated: 2024/12/10 19:08:56 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	collision(t_game *game, double ph[2], double ray[2])
{
	if (ph[0] < 1.0 || ph[0] > game->map_w - 1
		|| ph[1] < 1.0 || ph[1] > game->map_h)
		return (1);
	if (ph[0] == ceil(ph[0]))
		return (game->map[(int)ph[1]][(int)ph[0] - (ray[0] < 0)] == '1'
			|| game->map[(int)ph[1]][(int)ph[0] - (ray[0] < 0)] == 'D');
	else
		return (game->map[(int)ph[1] - (ray[1] < 0)][(int)ph[0]] == '1'
			|| game->map[(int)ph[1] - (ray[1] < 0)][(int)ph[0]] == 'D');
}

int	next_point(t_game *game, double photon[2], double m[2], double ray[2])
{
	double	option_1[2];
	double	option_2[2];

	option_1[0] = ceil(photon[0]) - (ray[0] < 0)
		+ (ray[0] > 0) * (ceil(photon[0]) == photon[0]);
	option_1[1] = photon[1] + m[0] * (option_1[0] - photon[0]);
	option_2[1] = ceil(photon[1]) - (ray[1] < 0)
		+ (ray[1] > 0) * (ceil(photon[1]) == photon[1]);
	option_2[0] = photon[0] + m[1] * (option_2[1] - photon[1]);
	if (fabs(option_1[0] - photon[0]) < fabs(option_2[0] - photon[0]))
	{
		photon[0] = option_1[0];
		photon[1] = option_1[1];
	}
	else
	{
		photon[0] = option_2[0];
		photon[1] = option_2[1];
	}
	return (collision(game, photon, ray));
}

void	gen_column(t_game *game, double scale, int column_id, double x_coord)
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
		ft_memcpy(&color, game->current_texture->pixels
			+ (4 * (int)(TEXTURE_S * x_coord)
				+ (4 * TEXTURE_S * (int)((i - start) / (2 * scale)))), 4);
		mlx_put_pixel(game->img, column_id, i, endian_switch(color));
		i++;
	}
	while (i < game->img_h)
		mlx_put_pixel(game->img, column_id, i++, game->floor);
}

double	generate_x_coord(t_game *g, double photon[2], double ray[2], double xc)
{
	if (photon[0] == ceil(photon[0]) && ray[0] > 0.0)
	{
		g->current_texture = g->w_texture;
		select_texture(g, (int)photon[0], (int)photon[1]);
		xc = photon[1] - floor(photon[1]);
	}
	else if (photon[0] == ceil(photon[0]) && ray[0] < 0.0)
	{
		g->current_texture = g->e_texture;
		select_texture(g, (int)photon[0] - 1, (int)photon[1]);
		xc = -photon[1] + ceil(photon[1]);
	}
	else if (ray[1] > 0.0)
	{
		g->current_texture = g->s_texture;
		select_texture(g, (int)photon[0], (int)photon[1]);
		xc = -photon[0] + floor(photon[0]);
	}
	else
	{
		g->current_texture = g->n_texture;
		select_texture(g, (int)photon[0], (int)photon[1] - 1);
		xc = photon[0] - ceil(photon[0]);
	}
	return (xc);
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
		ray[0] = game->dir[0] + game->dir[1] * (512 - i) * STEP;
		ray[1] = game->dir[1] - game->dir[0] * (512 - i) * STEP;
		photon[0] = game->pos[0];
		photon[1] = game->pos[1];
		m[0] = ray[1] / ray[0];
		m[1] = ray[0] / ray[1];
		while (!next_point(game, photon, m, ray))
			continue ;
		scale = 1 / (cos(STEP * (512 - i))
				* (hypot(photon[0] - game->pos[0], photon[1] - game->pos[1])));
		gen_column(game, scale, i, generate_x_coord(game, photon, ray, 0));
		++i;
	}
}
