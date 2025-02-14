/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:54:14 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/14 11:15:53 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


void	animation_up(int x , int y , t_map *map)
{
	int i;

	i = 0;
	while (i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar2, x * PXL, y * PXL);
	i = 0;
	while (i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar3, x * PXL, y * PXL);
	mlx_put_image_to_window(map->mlx, map->win, map->floor, x * PXL, y * PXL);
	i = 0;
	while (i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar3, x * PXL, (y-1) * PXL);
	i = 0;
	while(i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar2, x * PXL, (y-1) * PXL);
}

void	animation_down(int x , int y , t_map *map)
{
	int i;

	i = 0;
	while (i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar2, x * PXL, y * PXL);
	i = 0;
	while (i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar3, x * PXL, y * PXL);
	mlx_put_image_to_window(map->mlx, map->win, map->floor, x * PXL, y * PXL);
	i = 0;
	while (i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar3, x * PXL, (y + 1) * PXL);
	i = 0;
	while(i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar2, x * PXL, (y + 1) * PXL);
}

void	animation_right(int x , int y , t_map *map)
{
	int i;

	i = 0;
	while (i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar2, x * PXL, y * PXL);
	i = 0;
	while (i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar3, x * PXL, y * PXL);
	mlx_put_image_to_window(map->mlx, map->win, map->floor, x * PXL, y * PXL);
	i = 0;
	while (i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar3, (x + 1) * PXL, y * PXL);
	i=0;
	while(i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar2, (x + 1) * PXL, y * PXL);
}

void	animation_left(int x , int y , t_map *map)
{
	int i;

	i = 0;
	while (i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar2_lft, x * PXL, y * PXL);
	i = 0;
	while (i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar3_lft, x * PXL, y * PXL);
	mlx_put_image_to_window(map->mlx, map->win, map->floor, x * PXL, y * PXL);
	i = 0;
	while (i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar3_lft, (x - 1) * PXL, y * PXL);
	i = 0;
	while(i++ < 2000)
		mlx_put_image_to_window(map->mlx, map->win, map->avatar2_lft, (x - 1) * PXL, y * PXL);
}