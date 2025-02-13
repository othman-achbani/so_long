/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:49:39 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/13 17:32:14 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	attack1(t_map *map)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	x = map->pos_x;
	y = map->pos_y;
	while (i++ < 5000)
		mlx_put_image_to_window(map->mlx , map->win, map->attack1_1, x * PXL , y * PXL);
	i = 0;
	while(i++ < 10000)
		mlx_put_image_to_window(map->mlx , map->win, map->attack1_2, x * PXL , y * PXL);
	i = 0;
	while (i++ < 10000)
		mlx_put_image_to_window(map->mlx , map->win, map->attack1_3, x * PXL , y * PXL);
	mlx_put_image_to_window(map->mlx , map->win, map->avatar, x * PXL , y * PXL);
}
