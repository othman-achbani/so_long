/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:00:31 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/15 23:11:18 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_enemy_image(t_map *map)
{
	int	px;

	px = PXL;
	map->enemy = mlx_xpm_file_to_image(map->mlx, "../utils_xpm/enemy.xpm",&px, &px);
	if (!map->enemy)
		ft_map_error(map, 1);
	map->shot = mlx_xpm_file_to_image(map->mlx, "../utils_xpm/shot.xpm", &px, &px);
	if (!map->shot)
		ft_map_error(map, 1);
	map->shot_anim = mlx_xpm_file_to_image(map->mlx, "../utils_xpm/shot.xpm", &px, &px);
	if (!map->shot_anim)
		ft_map_error(map, 1);
	
}
