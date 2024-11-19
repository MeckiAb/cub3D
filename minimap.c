/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:24:23 by labderra          #+#    #+#             */
/*   Updated: 2024/11/19 14:08:46 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	minimap_init(t_game *game)
{
	unsigned int	i;

	game->mini = mlx_new_image(game->mlx, game->map_w * 20, game->map_h * 20);
	if (!game->mini)
		exit(1);
	i = 0;
	while (i < (game->mini->height * game->mini->width * 4))
		game->mini->pixels[i++] = 0x00;
	mlx_image_to_window(game->mlx, game->mini, 0,
		game->img_h - game->mini->height);
	game->mini->instances[0].z = 2;
}

void	minimap(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (j < game->mini->height)
	{
		i = 0;
		while (i < game->mini->width)
		{
			if (game->map[j / 20][i / 20] == '1')
				mlx_put_pixel(game->mini, i, j, 0xffffff66);
			else if(game->map[j / 20][i / 20] == 'D'
				|| game->map[j / 20][i / 20] == 'O')
				mlx_put_pixel(game->mini, i, j, 0x00ff0066);
			else if ((int)game->pos[0] == i / 20 && (int)game->pos[1] == j / 20)
				mlx_put_pixel(game->mini, i, j, 0xff000066);
			else 
				mlx_put_pixel(game->mini, i, j, 0x00000000);
			i++;
		}
		j++;
	}
}