/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:47:45 by labderra          #+#    #+#             */
/*   Updated: 2024/11/16 12:04:05 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	handle(void *param)
{
	t_game	*game;
	int32_t	delta_x;

	game = (t_game *)param;
	delta_x = game->cursor_x;
	mlx_get_mouse_pos(game->mlx, &(game->cursor_x), &(game->cursor_y));
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		check_strife(game, 0.1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		check_strife(game, -0.1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		check_movement(game, 0.1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		check_movement(game, -0.1);
	calculate_directions(game, (double)((delta_x - game->cursor_x) * PI / 360));
	generate_frame(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	
	if (argc != 2)
		return (1);
	game = init_game(argv[1]);
	if (!game)
		return (1);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	mlx_loop_hook(game->mlx, &handle, game);
	mlx_loop(game->mlx);
	free_all(game);
	
	return (0);
}
