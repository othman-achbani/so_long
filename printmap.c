/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 20:20:20 by oachbani          #+#    #+#             */
/*   Updated: 2025-01-28 20:20:20 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_map(t_map *map, int x, int y)
{
	char	tile;

	tile = map->tilesmap[y / PXL ][x / PXL];
	if (tile == 'E' || tile == 'P'|| tile == '0' || tile == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->floor, x, y);
	if (tile == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->coin, x , y);
	if (tile == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->door, x, y);
	if (tile == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->avatar, x, y-9);
	if (tile == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall, x, y);
}

void	pass_the_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	if (!map->tilesmap)
		exit(EXIT_FAILURE);
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			print_map(map, x * PXL, y * PXL);
			x++;
		}
		y++;
	}
	find_player(map);
	content_counter(map);
}
