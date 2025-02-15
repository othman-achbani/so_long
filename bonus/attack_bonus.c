/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:49:39 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/16 00:09:35 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void remove_enemy(t_map *map, int x, int y)
{
	int i;
	int	j;

	i = -1;
    while (++i < map->enemy_nbr)
    {
        if (map->enemy_pos[i].x == x && map->enemy_pos[i].y == y)
        {
			j = i;
            while(j < map->enemy_nbr)
            {
                map->enemy_pos[j] = map->enemy_pos[j + 1];
            }
            map->enemy_nbr--;
            break;
        }
    }
}

int	dropfire(t_map *map, int x, int y)
{
	int	i;

	i = 0;
	if (x > map->pos_x && map->tilesmap[y][x-1] != 'P')
        mlx_put_image_to_window(map->mlx, map->win, map->floor, (x - 1) * PXL, y * PXL);
	while (i++ < 4000)
	if (map->tilesmap[y][x] != '1' && map->tilesmap[y][x] != 'E')
		mlx_put_image_to_window(map->mlx, map->win,\
		map->shot, x * PXL, y  * PXL);
	if (map->tilesmap[y][x] == 'C')
	{
		map->tilesmap[y][x] = '0';
		map->c--;
	}
	if (map->tilesmap[y][x] == 'B')
	{
		map->tilesmap[y][x] = '0';
		mlx_put_image_to_window(map->mlx, map->win, map->shot_anim, x * PXL, y*PXL);
		remove_enemy(map, x, y);
	}
	else if(map->tilesmap[y][x] == '1' || map->tilesmap[y][x] == 'E')
		return (0);
return(1);
}

void	attack1_lft(t_map *map)
{
	int	i;
	int	y;
	int	x;

	x = map->pos_x;
	y = map->pos_y;
	i = 0;
	while (i++ < 5000)
			mlx_put_image_to_window(map->mlx , map->win,\
map->attack1_1_lft, x * PXL , y * PXL);
		i = 0;
		while(i++ < 7000)
			mlx_put_image_to_window(map->mlx , map->win, \
map->attack1_2_lft, x * PXL , y * PXL);
		i = 0;
		while (i++ < 7000)
			mlx_put_image_to_window(map->mlx , map->win, \
map->attack1_3_lft, x * PXL , y * PXL);
		mlx_put_image_to_window(map->mlx , map->win,\
 map->avatar_lft, x * PXL , y * PXL);
}
void	attack_right(t_map *map)
{
	int	i;
	int	y;
	int	x;

	x = map->pos_x;
	y = map->pos_y;
	i = 0;
	while (i++ < 5000)
		mlx_put_image_to_window(map->mlx , map->win, \
map->attack1_1, x * PXL , y * PXL);
		i = 0;
	while(i++ < 7000)
		mlx_put_image_to_window(map->mlx , map->win, \
map->attack1_2, x * PXL , y * PXL);
	i = 0;
	while (i++ < 7000)
		mlx_put_image_to_window(map->mlx , map->win, \
map->attack1_3, x * PXL , y * PXL);
	mlx_put_image_to_window(map->mlx , map->win, \
map->avatar, x * PXL , y * PXL);
}
void	attack1(t_map *map)
{
	int	i;
	int	y;
	int	x;

	x = map->pos_x;
	y = map->pos_y;
	i = 0;
	if (map->direction == LEFT)
		attack1_lft(map);
	else
		attack_right(map);
	while(1)
	{
		if (i++ % 500 == 0)
			if (!dropfire(map, ++x, y))
				break ;
	}
}
