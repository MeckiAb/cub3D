/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:56:53 by labderra          #+#    #+#             */
/*   Updated: 2024/11/16 20:30:05 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	calculate_directions(t_game *game, double d_alpha)
{
	game->alpha += d_alpha;
	if (game->alpha < 0.0)
		game->alpha += 2 * PI;
	if (game->alpha > 2* PI)
		game->alpha -= 2*PI;
	game->dir[0] = cos(game->alpha);
	game->dir[1] = sin(game->alpha);
}

void	check_movement(t_game *game, double move)
{
	double	new_pos[2];

	new_pos[0] = game->pos[0] + move * game->dir[0];
	new_pos[1] = game->pos[1] + move * game->dir[1];
	if (new_pos[0] > 0.0 && new_pos[0] < game->map_h 
		&& new_pos[1] > 0.0 && new_pos[1] < game->map_w
		&& game->map[(int)new_pos[0]][(int)new_pos[1]] != '1')
	{
		game->pos[0] = new_pos[0];
		game->pos[1] = new_pos[1];
	}
}

void	check_strife(t_game *game, double move)
{
	double	new_pos[2];

	new_pos[0] = game->pos[0] - move * game->dir[1];
	new_pos[1] = game->pos[1] + move * game->dir[0];
	if (new_pos[0] > 0.0 && new_pos[0] < game->map_h 
		&& new_pos[1] > 0.0 && new_pos[1] < game->map_w
		&& game->map[(int)new_pos[0]][(int)new_pos[1]] != '1')
	{
		game->pos[0] = new_pos[0];
		game->pos[1] = new_pos[1];
	}
}