/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:17:03 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/17 16:30:47 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_player_collision(t_map *map, int x, int y)
{
	if (map->tilesmap[y][x] == 'P')
		ft_loser(map);
}

void	update_position(t_map *map, int x, int y)
{
	map->tilesmap[y][x] = '0';
	mlx_put_image_to_window(map->mlx, map->win, map->floor, x * PXL, y * PXL);
}

int	for_normadd_(t_map *map, int x, int y)
{
	check_player_collision(map, x + 1, y);
	update_position(map, x, y);
	return (1);
}

int	for_normmines_(t_map *map, int x, int y)
{
	check_player_collision(map, x - 1, y);
	update_position(map, x, y);
	return (1);
}

void	initialized(t_map *map)
{
	int	m;

	m = -1;
	while (++m < map->enemy_nbr)
	{
		map->enemy_pos[m].direction = 1;
		map->enemy_pos[m].x = 0;
		map->enemy_pos[m].y = 0;
	}
}
