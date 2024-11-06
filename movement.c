/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:56:53 by labderra          #+#    #+#             */
/*   Updated: 2024/11/06 11:00:11 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calculate_directions(t_game *game, double d_alpha)
{
	game->alpha += d_alpha;
	game->dir_x = cos(game->alpha);
	game->dir_y = sin(game->alpha);
	game->tg_x = -1 * game->dir_y;
	game->tg_y = game->dir_x;
}