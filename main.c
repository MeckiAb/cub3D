/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:47:45 by labderra          #+#    #+#             */
/*   Updated: 2024/11/05 17:15:19 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
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
	
	return (0);
}
