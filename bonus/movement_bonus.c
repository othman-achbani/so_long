/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:59:16 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/17 22:42:45 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_win(t_map *map, int x, int y, int dir)
{
	if (dir == W)
		y -= 1;
	if (dir == S)
		y += 1;
	if (dir == A)
		x -= 1;
	if (dir == D)
		x += 1;
	if (map->tilesmap[y][x] == 'B')
		ft_loser(map);
	if (map->tilesmap[y][x] == 'C')
	{
		map->c--;
		map->tilesmap[y][x] = '0';
		if (map->c == 0)
			pass_the_map(map, OPEN);
	}
	if (map->tilesmap[y][x] == 'E' && map->c == 0)
		ft_winner(map);
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
		print_moves(++map->counter, map);
		animation_up(x, y, map);
		mlx_put_image_to_window(map->mlx, map->win, map->floor, x * PXL,
			y * PXL);
		map->tilesmap[y][x] = '0';
		y--;
		mlx_put_image_to_window(map->mlx, map->win, map->avatar, x * PXL,
			y * PXL);
		map->tilesmap[y][x] = 'P';
		map->pos_y = y;
		map->direction = RIGHT;
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
		print_moves(++map->counter, map);
		mlx_put_image_to_window(map->mlx, map->win, map->floor, x * PXL,
			y * PXL);
		map->tilesmap[y][x] = '0';
		animation_right(x, y, map);
		x++;
		map->pos_x = x;
		mlx_put_image_to_window(map->mlx, map->win, map->avatar, x * PXL,
			y * PXL);
		map->tilesmap[y][x] = 'P';
		map->direction = RIGHT;
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
		print_moves(++map->counter, map);
		animation_left(x, y, map);
		mlx_put_image_to_window(map->mlx, map->win, \
			map->floor, x * PXL, y * PXL);
		map->tilesmap[y][x] = '0';
		x--;
		map->pos_x = x;
		mlx_put_image_to_window(map->mlx, map->win, map->avatar_lft, \
			x * PXL, y * PXL);
		map->tilesmap[y][x] = 'P';
		map->direction = LEFT;
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
		print_moves(++map->counter, map);
		animation_down(x, y, map);
		mlx_put_image_to_window(map->mlx, map->win, map->floor, \
		x * PXL, y * PXL);
		map->tilesmap[y][x] = '0';
		y++;
		map->pos_y = y;
		mlx_put_image_to_window(map->mlx, map->win, map->avatar, \
		x * PXL, y * PXL);
		map->tilesmap[y][x] = 'P';
		map->direction = RIGHT;
	}
}
