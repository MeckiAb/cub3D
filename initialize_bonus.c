/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:48:48 by labderra          #+#    #+#             */
/*   Updated: 2024/11/19 19:04:51 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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

mlx_texture_t	**load_door_textures(char *str)
{
	mlx_texture_t	**txts;
	char			**split;
	int				i;

	i = -1;
	txts = malloc(sizeof(mlx_texture_t *) * 4);
	split = ft_split(str, ' ');
	txts[0] = mlx_load_png(split[1]);
	txts[1] = mlx_load_png(split[2]);
	txts[2] = mlx_load_png(split[3]);
	txts[3] = mlx_load_png(split[4]);
	while (++i < 4)
		if (!txts[i])
			return (free_split(split), free(txts), NULL);
	return (free_split(split), txts);
}

static int	load_textures(t_game *game)
{
	game->n_texture = mlx_load_png(game->t_map->n_text);
	game->s_texture = mlx_load_png(game->t_map->s_text);
	game->e_texture = mlx_load_png(game->t_map->e_text);
	game->w_texture = mlx_load_png(game->t_map->w_text);
	game->d_texture = load_door_textures(game->t_map->d_text);
	if (game->n_texture)
		game->ppu = game->n_texture->width;
	return (game->n_texture && game->s_texture && game->e_texture
		&& game->w_texture && game->d_texture);
}

static uint32_t	load_colors(char *color)
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
	game->mlx = mlx_init(IMG_WIDTH, IMG_HEIGHT, "Piramid RunBonus", 0);
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
	mlx_get_mouse_pos(game->mlx, &(game->cursor_x), &(game->cursor_y));
	minimap_init(game);
	return (game);
}
