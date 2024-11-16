/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utilities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:06:03 by jose-rig          #+#    #+#             */
/*   Updated: 2024/11/16 19:23:24 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*remove_spaces_end(char **full_map, int i)
{
	return (ft_substr(full_map[i], 0, ft_space(full_map[i] - 1)));
}
