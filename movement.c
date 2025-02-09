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


static void	check_win(t_map *map, int x, int y , int dir)
{
	if (dir == W)
		y -= 1;
	if (dir == S)
		y += 1;
	if (dir == A)
		x -= 1;
	if (dir == D)
		x += 1;
	if (map->tilesmap[y][x] == 'C')
		map->c--;
	if (map->tilesmap[y][x] == 'E' && map->c == 0)
	{
		// i need to add win function here ;
		
	}
}
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
		map->tilesmap[y][x] = '0';
		map->tilesmap[y][x] = 'P';
		pass_the_map(map);
	}
}
void	move_right(t_map *map)
{
	int	y;
	int	x;

	y = map->pos_y;
	x = map->pos_x;
	if (y < map->y && map->tilesmap[y][x + 1] != '1')
	{
		map->tilesmap[y][x] = '0';
		x++;
		map->pos_x = x;
		map->tilesmap[y][x] = '0';
		map->tilesmap[y][x] = 'P';
		pass_the_map(map);
	}
}
void	move_left(t_map *map)
{
	int	y;
	int	x;

	y = map->pos_y;
	x = map->pos_x;
	if (y < map->y && map->tilesmap[y][x - 1] != '1')
	{
		map->tilesmap[y][x] = '0';
		x--;
		map->pos_x = x;
		map->tilesmap[y][x] = '0';
		map->tilesmap[y][x] = 'P';
		pass_the_map(map);
	}
}

void	move_down(t_map *map)
{
	int	y;
	int	x;

	y = map->pos_y;
	x = map->pos_x;
	if (y < map->y && map->tilesmap[y + 1][x] != '1')
	{
		map->tilesmap[y][x] = '0';
		y++;
		map->pos_y = y;
		map->tilesmap[y][x] = '0';
		map->tilesmap[y][x] = 'P';
		pass_the_map(map);
	}
}