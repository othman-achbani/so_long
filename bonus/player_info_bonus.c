/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:19:11 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/16 00:06:06 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_player(t_map *map)
{
	map->pos_x = 0;
	map->pos_y = 0;

	while(map->pos_y < map->y)
	{
		map->pos_x = 0;
		while (map->pos_x < map->x)
		{
			if (map->tilesmap[map->pos_y][map->pos_x] == 'P')
				return ;
			map->pos_x++;
		}
	map->pos_y++;
	}
}
void	enemy_counter(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = -1;
	while (y < map->y)
	{
		while (++x < map->x)
			if (map->tilesmap[y][x] == 'B')
				map->enemy_nbr++;
		x = -1;
		y++;
	}
}
void	scan_enemy(t_map *map)
{
	int	y;
	int	x;
	int	m;

	y = -1;
	enemy_counter(map);
	map->enemy_pos = malloc(sizeof(t_enemy) * map->enemy_nbr);
	if (!map->enemy_pos)
		ft_map_error(map, 1);
	initialized(map);
	m = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
			if (map->tilesmap[y][x] == 'B')
			{
				map->enemy_pos[++m].x = x;
				map->enemy_pos[m].y = y;
			}
	}
}

static void	check_add(t_map *map , int i)
{
	t_enemy *enemy;
	
	enemy = &map->enemy_pos[i];
	if (enemy->direction == 1)
	{
		if (map->tilesmap[enemy->y][enemy->x + 1 ] == '0'\
|| map->tilesmap[enemy->y][enemy->x + 1] == 'P')
			enemy->x += for_normadd_(map, enemy->x, enemy->y);
		else
			enemy->direction = -1;
	}
	else
	{
		if (map->tilesmap[enemy->y][enemy->x - 1 ] == '0' \
|| map->tilesmap[enemy->y][enemy->x - 1 ] == 'P')
			enemy->x -= for_normmines_(map, enemy->x, enemy->y);
		else
			enemy->direction = 1;
	}
	draw_enemy_position(map, enemy->x, enemy->y);
}

int	move_enemy(t_map *map)
{
	static int frame_counter ;
    int i;

    frame_counter++;
    if (frame_counter % 600 == 0) // Update enemies every 10 frames
    {
        i = -1;
        while (++i < map->enemy_nbr)
        {
            check_add(map, i);
        }
    }
    return (0);
}
