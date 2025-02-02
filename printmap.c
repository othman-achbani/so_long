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

static void	print_map(t_map *map, s_var var, int x, int y)
{
	char	tile;

	tile = map->tilesmap[y / PXL ][x / PXL];
	if (tile == 'E' || tile == 'P'|| tile == '0' || tile == 'C')
		mlx_put_image_to_window(var.mlx, var.win, map->floor, x, y);
	if (tile == 'C')
		mlx_put_image_to_window(var.mlx, var.win, map->coin, x, y);
	if (tile == 'E')
		mlx_put_image_to_window(var.mlx, var.win, map->door, x, y);
	if (tile == '1')
		mlx_put_image_to_window(var.mlx, var.win, map->wall, x, y);
}

void	pass_the_map(t_map *map , s_var var)
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
			print_map(map, var, x * PXL, y * PXL);
			x++;
		}
		y++;
	}
}
