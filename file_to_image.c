/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 16:16:21 by oachbani          #+#    #+#             */
/*   Updated: 2025-01-27 16:16:21 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_image(t_map *map, s_var var)
{
	int	pixel;

	pixel = PXL;
	map->door = mlx_xpm_file_to_image(var.mlx , "./utils_xpm/door.xpm", &pixel , &pixel);
	map->floor = mlx_xpm_file_to_image(var.mlx , "./utils_xpm/stone_floor.xpm", &pixel, &pixel);
	map->wall = mlx_xpm_file_to_image(var.mlx , "./utils_xpm/wall.xpm", &pixel , &pixel);
	player_image(map, var);
}

void	player_image(t_map *map , s_var var)
{
	int	pixel;

	pixel = PXL;
	map->avatar = mlx_xpm_file_to_image(var.mlx , "./utils_xpm/avatarmv1.xpm", &pixel , &pixel);
	map->avatar2 = mlx_xpm_file_to_image(var.mlx , "./utils_xpm/avatarmv2.xpm", &pixel , &pixel);
	map->avatar3 = mlx_xpm_file_to_image(var.mlx , "./utils_xpm/avatarmv3.xpm", &pixel , &pixel);
}