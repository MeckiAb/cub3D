/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:15:50 by labderra          #+#    #+#             */
/*   Updated: 2024/11/06 13:58:06 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

uint8_t	*generate_column(t_game *game, int i)
{
	double	ray_x;
	double	ray_y;
	double	foton_x;
	double	foton_y;
	int		collision;

	ray_x = game->dir_x + game->tg_x * i * STEP;
	ray_y = game->dir_y + game->tg_y * i * STEP;
	foton_x = game->pos_x;
	foton_y = game->pos_y;
	collision = 0;
	while (!collision)
	{
		if (ray_x <)
	}
}

void	generate_frame(t_game *game)
{
	int		i;
	int		j;
	uint8_t	*column;
	
	i = 0;
	while (i < game->img_w)
	{
		column = generate_column(game, i);
		j = 0;
		while (j < game->img_h)
		{
			game->img->pixels[4 * (i + game->img_w * j)] = column[j];
			++j;
		}
		free(column);
		++i;
	}
}
