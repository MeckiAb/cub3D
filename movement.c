/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:56:53 by labderra          #+#    #+#             */
/*   Updated: 2024/11/19 13:08:12 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calculate_directions(t_game *game, double d_alpha)
{
	printf("DIRECTION BEFdir[0]:%f dir[1]:%f\n", game->dir[0], game->dir[1]);
	game->alpha += d_alpha;
	if (game->alpha < 0.0)
		game->alpha += 2 * PI;
	if (game->alpha > 2* PI)
		game->alpha -= 2*PI;
	game->dir[0] = cos(game->alpha);
	game->dir[1] = sin(game->alpha);
	printf("DIRECTION AFTdir[0]:%f dir[1]:%f\n", game->dir[0], game->dir[1]);
}

void	check_movement(t_game *game, double move)
{
	double	new_pos[2];
	
	new_pos[0] = game->pos[0] + move * game->dir[0];
	new_pos[1] = game->pos[1] + move * game->dir[1];
	printf("MV BEF newpos[0]:%f newpos[1]:%f\n", game->pos[0], game->pos[1]);
	printf("newpos[0]%f = gpos[0]%f + move%f * gdir[0]%f\n", new_pos[0], game->pos[0], move, game->dir[0]);
	printf("newpos[1]%f = gpos[1]%f + move%f * gdir[1]%f\n", new_pos[1], game->pos[1], move, game->dir[1]);
	if (new_pos[0] > 0.0 && new_pos[0] < game->map_w
		&& new_pos[1] > 0.0 && new_pos[1] < game->map_h)
	{
		game->pos[0] = new_pos[0];
		game->pos[1] = new_pos[1];
	}
	printf("MV AFT pos[0]:%f pos[1]:%f\n", game->pos[0], game->pos[1]);
}