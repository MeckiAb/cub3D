/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:48:48 by labderra          #+#    #+#             */
/*   Updated: 2024/11/16 20:17:01 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_all(t_game *game)
{

	mlx_delete_texture(game->n_texture);
	mlx_delete_texture(game->s_texture);
	mlx_delete_texture(game->e_texture);
	mlx_delete_texture(game->w_texture);
	mlx_delete_image(game->mlx, game->img);
	mlx_terminate(game->mlx);
	free_map(game->t_map);
	free(game);
}

static int	load_map(t_game *game)
{	
	game->map = game->t_map->map;
	game->map_w = game->t_map->map_w;
	game->map_h = game->t_map->map_h;
	game->pos[0] = game->t_map->p_x + 0.5;
	game->pos[1] = game->t_map->p_y + 0.5;
	/* game->pos[0] = 3.5;
	game->pos[1] = 4.5; */
	if (game->t_map->facing == 'N')
		game->alpha = PI * 0;
	if (game->t_map->facing == 'E')
		game->alpha = PI * 1.5;
	if (game->t_map->facing == 'S')
		game->alpha = PI * 1;
	if (game->t_map->facing == 'W')
		game->alpha = PI * 0.5;
	//game->alpha = PI * 0; //(0, 90,180, 270)
	game->dir[0] = cos(game->alpha);
	game->dir[1] = sin(game->alpha);
	return (-1 * (game->map == NULL));
}

static int load_textures(t_game *game)
{
	game->n_texture = mlx_load_png(game->t_map->n_text);
	game->s_texture = mlx_load_png(game->t_map->s_text);
	game->e_texture = mlx_load_png(game->t_map->e_text);
	game->w_texture = mlx_load_png(game->t_map->w_text);
	game->ppu = game->n_texture->width;
	game->ceiling = 0xebc934ff;
	game->floor = 0x915603ff;
	return (game->n_texture && game->s_texture && game->e_texture
		&& game->w_texture);
}

t_game	*init_game(t_map *t_map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->t_map = t_map;
	game->mlx = mlx_init(IMG_WIDTH, IMG_HEIGHT, "Piramid Run", 0);
	if (!game->mlx)
		return (NULL);
	game->img = mlx_new_image(game->mlx, IMG_WIDTH, IMG_HEIGHT);
	if (load_textures(game) == -1 || load_map(game) == -1
			|| !game->img)
		return (NULL);
	game->img_w = IMG_WIDTH;
	game->img_h = IMG_HEIGHT;
	return (game);
}
