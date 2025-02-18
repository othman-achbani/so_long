/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:20:20 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/17 17:39:48 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_map(t_map *map, int x, int y, int door)
{
	char	t;

	t = map->tilesmap[y / PXL][x / PXL];
	if (t != '0' && t != '1' && t != 'C'
		&& t != 'E' && t != 'P' && t != 'B' && t)
		ft_map_error(map, NO_MAP);
	if (t == 'E' || t == 'P' || t == '0' || t == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->floor, x, y);
	if (t == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->coin, x, y + 2);
	if (t == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->avatar, x, y);
	if (t == 'E' && door == CLOSED)
		mlx_put_image_to_window(map->mlx, map->win, map->door, x, y);
	if (t == 'E' && door == OPEN)
		mlx_put_image_to_window(map->mlx, map->win, map->door_closed, x, y);
	if (t == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall, x, y);
	if (t == 'B')
		mlx_put_image_to_window(map->mlx, map->win, map->enemy, x, y);
}

void	pass_the_map(t_map *map, int door)
{
	int	y;
	int	x;

	y = 0;
	if (!map->tilesmap)
		exit(EXIT_FAILURE);
	while (y < map->y)
	{
		x = -1;
		while (++x < map->x)
			print_map(map, x * PXL, y * PXL, door);
		y++;
	}
	mlx_string_put(map->mlx, map->win, PXL + 20, 32, 0xffffff, "MOVES:");
	mlx_string_put(map->mlx, map->win, PXL * 2, 32, 0x00ff00, "0");
	find_player(map);
}
