/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:48:48 by labderra          #+#    #+#             */
/*   Updated: 2024/11/19 17:06:21 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_all(t_game *game)
{
	if (game && game->n_texture)
		mlx_delete_texture(game->n_texture);
	if (game && game->s_texture)
		mlx_delete_texture(game->s_texture);
	if (game && game->e_texture)
		mlx_delete_texture(game->e_texture);
	if (game && game->w_texture)
		mlx_delete_texture(game->w_texture);
	if (game)
	{
		mlx_delete_image(game->mlx, game->img);
		mlx_terminate(game->mlx);
		free_map(game->t_map);
		free(game);
	}
}

static int	load_map(t_game *game)
{	
	game->map = game->t_map->map;
	game->map_w = game->t_map->map_w;
	game->map_h = game->t_map->map_h;
	game->pos[0] = game->t_map->p_x + 0.5;
	game->pos[1] = game->t_map->p_y + 0.5;
	if (game->t_map->facing == 'N')
		game->alpha = PI * 0.5;
	if (game->t_map->facing == 'E')
		game->alpha = PI * 1.0;
	if (game->t_map->facing == 'S')
		game->alpha = PI * 1.5;
	if (game->t_map->facing == 'W')
		game->alpha = PI * 0.0;
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
	if(game->n_texture)
		game->ppu = game->n_texture->width;
	return (game->n_texture && game->s_texture && game->e_texture
		&& game->w_texture);
}

static uint32_t load_colors(char *color)
{
	char		**new;
	uint32_t	result;

	new = ft_split(color, ',');
	result = atoi(new[0]) << 24 | atoi(new[1]) << 16 | atoi(new[2]) << 8 | 0xff;
	free_split(new);
	return (result);
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
		return (free_all(game), NULL);
	game->img = mlx_new_image(game->mlx, IMG_WIDTH, IMG_HEIGHT);
	if (load_textures(game) == 0 || load_map(game) == -1
			|| !game->img)
		return (free_all(game), NULL);
	game->ceiling = load_colors(game->t_map->c_color);
	game->floor = load_colors(game->t_map->f_color);
	game->img_w = IMG_WIDTH;
	game->img_h = IMG_HEIGHT;
	return (game);
}
