/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:19:11 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/10 16:07:38 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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