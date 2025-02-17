/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:58:24 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/16 20:27:04 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void move_enemy_right(t_map *map, t_enemy **enemy)
{
    if (map->tilesmap[(*enemy)->y][(*enemy)->x + 1] == '0')
    {
		map->tilesmap[(*enemy)->y][(*enemy)->x] = '0';
        clear_enemy_position(map, (*enemy)->x, (*enemy)->y);
        (*enemy)->x++;
    }
    else
    {
        (*enemy)->direction = -1;
    }
}

void move_enemy_left(t_map *map, t_enemy **enemy)
{
    if (map->tilesmap[(*enemy)->y][(*enemy)->x - 1] == '0')
    {
		map->tilesmap[(*enemy)->y][(*enemy)->x] = '0';
        clear_enemy_position(map, (*enemy)->x, (*enemy)->y);
        (*enemy)->x--;
    }
    else
        (*enemy)->direction = 1;
}

void clear_enemy_position(t_map *map, int x, int y)
{
    mlx_put_image_to_window(map->mlx, map->win, map->floor, x * PXL, y * PXL);
}

void draw_enemy_position(t_map *map, int x, int y)
{
    mlx_put_image_to_window(map->mlx, map->win, map->enemy, x * PXL, y * PXL);
	map->tilesmap[y][x] = 'B';
}
int	dropfire_lft(t_map *map, int x, int y)
{
	int	i;

	i = 0;
	if (map->tilesmap[y][x+1] != 'P' && map->tilesmap[y][x+1] != 'C')
        mlx_put_image_to_window(map->mlx, map->win, map->floor, (x+1) * PXL, y * PXL);
	while (i++ < 4000)
	if (map->tilesmap[y][x] != '1' && map->tilesmap[y][x] != 'E' && map->tilesmap[y][x] != 'C')
		mlx_put_image_to_window(map->mlx, map->win,\
		map->shot_lft, x * PXL, y  * PXL);
	if (map->tilesmap[y][x] == 'B')
	{
		map->tilesmap[y][x] = '0';
		remove_enemy(map, x, y);
	}
	else if(map->tilesmap[y][x] == '1' || map->tilesmap[y][x] == 'E')
		return (0);
return(1);
}
