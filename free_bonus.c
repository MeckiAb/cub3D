/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:04:03 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/19 19:22:35 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	if (game && game->n_texture)
		mlx_delete_texture(game->n_texture);
	if (game && game->s_texture)
		mlx_delete_texture(game->s_texture);
	if (game && game->e_texture)
		mlx_delete_texture(game->e_texture);
	if (game && game->w_texture)
		mlx_delete_texture(game->w_texture);
	if (game && game->d_texture)
	{
		while (i < 4)
			mlx_delete_texture(game->d_texture[i++]);
		free(game->d_texture);
	}
	if (game)
	{
		mlx_delete_image(game->mlx, game->img);
		mlx_terminate(game->mlx);
		free_map(game->t_map);
		free(game);
	}
}
