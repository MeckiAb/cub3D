/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:47:45 by labderra          #+#    #+#             */
/*   Updated: 2024/11/16 18:16:00 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		calculate_directions(game, PI / 36);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		calculate_directions(game, -1 * PI / 36);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		check_movement(game, 0.1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		check_movement(game, -0.1);
	generate_frame(game);
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
