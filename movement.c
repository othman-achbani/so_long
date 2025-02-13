/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:59:16 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/13 14:38:51 by oachbani         ###   ########.fr       */
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
		ft_winner(map);
	}
}
void	move_up(t_map *map)
{
	int	y;
	int	x;

	y = map->pos_y;
	x = map->pos_x;
	check_win(map, x, y, W);
	if (y < map->y && map->tilesmap[y - 1][x] != '1')
	{
		if (map->tilesmap[y - 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		print_moves(++map->counter);
		animation_up(x, y,map);
		map->tilesmap[y][x] = '0';
		y--;
		map->tilesmap[y][x] = 'P';
		map->pos_y = y;
		pass_the_map(map);
	}
}

void	move_right(t_map *map)
{
	int	y;
	int	x;

	y = map->pos_y;
	x = map->pos_x;
	check_win(map, x, y, D);
	if (y < map->y && map->tilesmap[y][x + 1] != '1')
	{
		if (map->tilesmap[y][x + 1] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		print_moves(++map->counter);
		map->tilesmap[y][x] = '0';
		animation_right(x, y, map);
		x++;
		map->pos_x = x;
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
	check_win(map, x, y, A);
	if (y < map->y && map->tilesmap[y][x - 1] != '1')
	{
		if (map->tilesmap[y][x - 1] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		print_moves(++map->counter);
		animation_left(x, y, map);
		map->tilesmap[y][x] = '0';
		x--;
		map->pos_x = x;
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
	check_win(map, x, y, S);
	if (y < map->y && map->tilesmap[y + 1][x] != '1')
	{
		if (map->tilesmap[y + 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		print_moves(++map->counter);
		animation_down(x, y, map);
		map->tilesmap[y][x] = '0';
		y++;
		map->pos_y = y;
		map->tilesmap[y][x] = 'P';
		pass_the_map(map);
	}
}