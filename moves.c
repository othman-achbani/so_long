/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 12:47:38 by oachbani          #+#    #+#             */
/*   Updated: 2025-01-27 12:47:38 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit(int keycode,t_map *map)
{
	if (keycode == ESC)
	{
		ft_putstr_fd("the ESC key is pressed the window will close now \n", 1);
		mlx_destroy_window(map->mlx, map->win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == W)
		move_up(map);
	else if (keycode == S)
		move_down(map);
	else if (keycode == A)
		move_left(map);
	else if (keycode == D)
		move_right(map);
	printf("You moved %d times.\n", ++map->counter);
}

void	content_counter(t_map *map)
{
	int		x;
	int		y;

	map->c = 0;
	map->e = 0;
	y = 0;
	x = 0;
	while(y < map->y)
	{
		while (x < map->x)
		{
			if (map->tilesmap[y][x] == 'C')
				map->c++;
			else if (map->tilesmap[y][x] == 'E');
				map->e++;
			x++;
		}
		x = 0;
		y++;
	}
}