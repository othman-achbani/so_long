/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 12:59:16 by oachbani          #+#    #+#             */
/*   Updated: 2025-02-06 12:59:16 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map)
{
	int	y;
	int	x;

	y = map->pos_y;
	x = map->pos_x;
	if (y < map->y && map->tilesmap[y - 1][x] != '1')
	{
		map->tilesmap[y][x] = '0';
		y--;
		map->pos_y = y;
		mlx_put_image_to_window(map->mlx , map->win, map->floor,x * PXL, y * PXL);
		map->tilesmap[y][x] = 'P';
		pass_the_map(map);
	}

}