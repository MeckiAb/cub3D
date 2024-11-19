/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:56:53 by labderra          #+#    #+#             */
/*   Updated: 2024/11/19 18:24:12 by labderra         ###   ########.fr       */
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
	if (new_pos[0] > 0.0 && new_pos[0] < game->map_w 
		&& new_pos[1] > 0.0 && new_pos[1] < game->map_h
		&& game->map[(int)new_pos[1]][(int)new_pos[0]] != '1'
		&& game->map[(int)new_pos[1]][(int)new_pos[0]] != 'D')
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
	if (new_pos[0] > 0.0 && new_pos[0] < game->map_w
		&& new_pos[1] > 0.0 && new_pos[1] < game->map_h
		&& game->map[(int)new_pos[1]][(int)new_pos[0]] != '1'
		&& game->map[(int)new_pos[1]][(int)new_pos[0]] != 'D')
	{
		game->pos[0] = new_pos[0];
		game->pos[1] = new_pos[1];
	}
}

void	check_door(t_game *game, double distance)
{
	double	target[2];

	target[0] = game->pos[0] + distance * game->dir[0];
	target[1] = game->pos[1] + distance * game->dir[1];
	if (game->map[(int)target[1]][(int)target[0]] == 'D')
		game->map[(int)target[1]][(int)target[0]] = 'O';
	else if (game->map[(int)target[1]][(int)target[0]] == 'O')
		game->map[(int)target[1]][(int)target[0]] = 'D';
}
