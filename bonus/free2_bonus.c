/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:37:23 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/17 17:38:20 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroyer_dir(t_map *map)
{
	if (map->attack1_1_lft)
		mlx_destroy_image(map->mlx, map->attack1_1_lft);
	if (map->attack1_2_lft)
		mlx_destroy_image(map->mlx, map->attack1_2_lft);
	if (map->attack1_3_lft)
		mlx_destroy_image(map->mlx, map->attack1_3_lft);
	if (map->avatar_lft)
		mlx_destroy_image(map->mlx, map->avatar_lft);
	if (map->avatar2_lft)
		mlx_destroy_image(map->mlx, map->avatar2_lft);
	if (map->avatar3_lft)
		mlx_destroy_image(map->mlx, map->avatar3_lft);
	if (map->door_closed)
		mlx_destroy_image(map->mlx, map->door_closed);
	if (map->enemy)
		mlx_destroy_image(map->mlx, map->enemy);
	if (map->mlx && map->win)
	{
		mlx_destroy_window(map->mlx, map->win);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
}
