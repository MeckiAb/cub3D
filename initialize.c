/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:48:48 by labderra          #+#    #+#             */
/*   Updated: 2024/11/08 00:20:17 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <string.h>

char	**ft_split(char const *s, char c);

static int	load_map(t_game *game, char *map_file)
{
	char	*map_mock ="1111111.1001001.1000001.1000001.1000001.100N001.1111111";
	
	(void)map_file;
	game->map = ft_split(map_mock, '.');
	game->map_w = 7;
	game->map_h = 7;
	game->pos[0] = 3.5;
	game->pos[1] = 4.5;
	game->dir[0] = 0;
	game->dir[1] = 1;
	return (-1 * (game->map == NULL));
}

static int load_textures(t_game *game, char *map_file)
{
	mlx_texture_t	*text_mock;

	(void)map_file;
	text_mock = mlx_load_png("src/north.png");
	game->n_texture = mlx_texture_to_image(game->mlx, text_mock);
	text_mock = mlx_load_png("src/south.png");
	game->s_texture = mlx_texture_to_image(game->mlx, text_mock);
	text_mock = mlx_load_png("src/east.png");
	game->e_texture = mlx_texture_to_image(game->mlx, text_mock);
	text_mock = mlx_load_png("src/west.png");
	game->w_texture = mlx_texture_to_image(game->mlx, text_mock);
	game->ppu = game->n_texture->width;
	game->ceiling = 0xebc934ff;
	game->floor = 0x915603ff;
	mlx_delete_texture(text_mock);
	return (game->n_texture && game->s_texture && game->e_texture
		&& game->w_texture);
}

t_game	*init_game(char *map_file)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx_init(IMG_WIDTH, IMG_HEIGHT, "Piramid Run", 0);
	if (!game->mlx)
		return (NULL);
	game->img = mlx_new_image(game->mlx, IMG_WIDTH, IMG_HEIGHT);
	if (load_textures(game, map_file) == -1 || load_map(game, map_file) == -1
			|| !game->img)
		return (NULL);
	game->img_w = IMG_WIDTH;
	game->img_h = IMG_HEIGHT;
	return (game);
}