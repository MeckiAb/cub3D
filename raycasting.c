/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:15:50 by labderra          #+#    #+#             */
/*   Updated: 2024/11/05 18:02:28 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

uint8_t	*generate_column(t_game *game, int i)
{
	
}

void	generate_frame(t_game *game)
{
	int		i;
	int		j;
	uint8_t	*column;
	
	i = 0;
	while (i < game->img_w)
	{
		column = generate_column(game, i);
		j = 0;
		while (j < game->img_h)
		{
			game->img->pixels[4 * (i * game->img_w + j)] = column[j];
			++j;
		}
		free(column);
		++i;
	}
}

