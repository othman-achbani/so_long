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
	// printf("%d | %d \n", map->pos_x , map->pos_y);
	// printf("good\n");
	// printf("%d this is y \n", y);
	// printf("%d this is the map y \n", map->y);
	// printf("%c this is the map tilesmap \n", map->tilesmap[y-1][x]);
	if (y < map->y && map->tilesmap[y - 1][x] != '1')
	{
		mlx_put_image_to_window(map->mlx , map->win, map->floor,x * PXL, y * PXL);
		map->tilesmap[y][x] = '0';
		y--;
		map->pos_y = y;
		mlx_put_image_to_window(map->mlx , map->win, map->floor,x * PXL, y * PXL);
		mlx_put_image_to_window(map->mlx, map->win, map->avatar , x * PXL , y * PXL);
		map->tilesmap[y][x] = 'P';
	}

}