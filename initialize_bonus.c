/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:48:48 by labderra          #+#    #+#             */
/*   Updated: 2024/11/16 11:58:42 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	free_all(t_game *game)
{
	int	i;

	mlx_delete_texture(game->n_texture);
	mlx_delete_texture(game->s_texture);
	mlx_delete_texture(game->e_texture);
	mlx_delete_texture(game->w_texture);
	mlx_delete_image(game->mlx, game->img);
	mlx_terminate(game->mlx);
	i = 0;
	while (game->map && game->map[i])
		free(game->map[i++]);
	if (game->map)
		free(game->map);
	free(game);
}

static int	load_map(t_game *game, char *map_file)
{
	char	*map_mock ="1111111.1001001.1000001.1000001.1000001.100N001.1111111";
	
	(void)map_file;
	game->map = ft_split(map_mock, '.');
	game->map_w = 7;
	game->map_h = 7;
	game->pos[0] = 3.5;
	game->pos[1] = 1.5;
	game->alpha = PI * 180;
	game->dir[0] = cos(game->alpha);
	game->dir[1] = sin(game->alpha);
	return (-1 * (game->map == NULL));
}

static int load_textures(t_game *game, char *map_file)
{
	(void)map_file;
	game->n_texture = mlx_load_png("src/north.png");
	game->s_texture = mlx_load_png("src/south.png");
	game->e_texture = mlx_load_png("src/east.png");
	game->w_texture = mlx_load_png("src/west.png");
	game->ppu = game->n_texture->width;
	game->ceiling = 0xebc934ff;
	game->floor = 0x915603ff;
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
	game->cursor_x = IMG_WIDTH / 2;
	game->cursor_y = IMG_HEIGHT / 2;
	mlx_set_mouse_pos(game->mlx, IMG_WIDTH / 2 , IMG_HEIGHT / 2);
	return (game);
}
