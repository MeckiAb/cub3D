/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:15:50 by labderra          #+#    #+#             */
/*   Updated: 2024/11/08 13:40:43 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	next_point(double **photon, double m[2], double ray[2])
{
	if (m[0] = INFINITY && ray[1] > 0.0)
		(*photon)[1] = floor((*photon)[1]) + 1;
	else if (m[0] = INFINITY && ray[1] < 0.0)
		(*photon)[1] = ceil((*photon)[1]) - 1;
	else if (m[1] = INFINITY && ray[0] > 0.0)
		(*photon)[0] = floor((*photon)[0]) + 1;
	else if (m[1] = INFINITY && ray[0] < 0.0)
		(*photon)[0] = ceil((*photon)[0]) - 1;
	else
	{
		
	}
}

uint32_t	*generate_column(t_game *game, double ray[2])
{
	double	photon[2];
	int		i;
	double	scale;
	uint32_t	*column;
	double	m[2];
	int		collision;

	collision = 0;
	photon[0] = game->pos[0];
	photon[1] = game->pos[1];
	m[0] = ray[1] / ray[0];
	m[1] = ray[0] / ray[1];
	while (!collision)
		collision = next_point(&photon, m, ray);
	scale = 1.0 / hypot(photon[0] - game->pos[0], photon[1] - game->pos[1]);
	
	
//función next_point con &foton, pendiente y rayo, me actualiza foton y me dice si hay colision
// si hay colision, la coordenada cero me dice orientacion y la dirección del rayo me dice 
// cara tocada. la coordenada que no es cero me dice el punto de la textura.
	
	while (ray[0] == 0.0 && game->map[(int)photon[0]][(int)photon[1]] != '1')
		if (ray[1] > 0)
			photon[1] = floor(photon[1]) + 1;
		else
			photon[1] = ceil(photon[1]) - 1;
	while (ray[1] == 0.0 && game->map[(int)photon[0]][(int)photon[1]] != '1')
		if (ray[0] > 0)
			photon[0] = floor(photon[0]) + 1;
		else
			photon[0] = ceil(photon[0]) - 1;
	
	if (ray[0] == 0.0) printf("%f\n", scale);
	
	column = malloc(sizeof(uint32_t) * game->img_h);
	if (!column)
		exit(1);
	i = 0;
	while (i < (game->img_h - PIXELS_X_UNIT * scale) / 2)
		column[i++] = game->ceiling;
	while (i < (game->img_h + PIXELS_X_UNIT * scale) / 2 && i < game->img_h)
		column[i++] = 0x000044ff;
	while (i < game->img_h)
		column[i++] = game->floor;
	return ((uint32_t *)column);	
}

void	generate_frame(t_game *game)
{
	int		i;
	int		j;
	double	ray[2];
	uint32_t	*column;
	
	i = 0;
	while (i < game->img_w)
	{
		ray[0] = game->dir[0] + game->dir[1] * (i -  512) * STEP;
		ray[1] = game->dir[1] + game->dir[0] * (i + 512) * STEP;
		column = generate_column(game, ray);
		j = 0;
		while (j < game->img_h)
		{
			game->img->pixels[4 * (i + game->img_w * j)] = 0xff;//(column)[j];
			++j;
		}
		free(column);
		++i;
	}
}


dir x = 0
dir y = 1

p x = -1
p y = 0

ray x = -1
ray y = 1