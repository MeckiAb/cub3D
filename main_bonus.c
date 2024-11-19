/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:47:45 by labderra          #+#    #+#             */
/*   Updated: 2024/11/19 19:22:43 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

uint32_t	endian_switch(uint32_t color)
{
	return ((color & 0x000000ff) << 24 | (color & 0x0000ff00) << 8
		| (color & 0x00ff0000) >> 8 | (color & 0xff000000) >> 24);
}

void	select_texture(t_game *game, int x, int y)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	if (game->map[y][x] == 'D')
		game->current_texture = game->d_texture[(tv.tv_usec / 250000) % 4];
}

void	handle(void *param)
{
	t_game	*game;
	int32_t	d_x;

	game = (t_game *)param;
	d_x = game->cursor_x;
	mlx_get_mouse_pos(game->mlx, &(game->cursor_x), &(game->cursor_y));
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		check_strife(game, -0.1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		check_strife(game, 0.1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		check_movement(game, 0.1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		check_movement(game, -0.1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_F))
		check_door(game, 0.8);
	calculate_directions(game, (double)((-d_x + game->cursor_x) * PI / 360));
	generate_frame(game);
	minimap(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_map	map;

	if (main_parse(argc, argv, &map))
		return (free_map(&map), 1);
	game = init_game(&map);
	if (!game)
		return (1);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	mlx_loop_hook(game->mlx, &handle, game);
	mlx_loop(game->mlx);
	free_all(game);
	return (0);
}
