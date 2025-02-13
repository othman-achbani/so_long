/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:45:31 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/13 15:18:27 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_checker(t_map *map , char *filename)
{
	map->y = 0;
	map->counter = 0;
	map->filename = filename;
	check_file(map);
	get_tilesmap(map);
	check_lenmap(map);
	check_wall(map);
	content_counter(map);
	check_valid_path(map);
}

int main (int ac, char **av)
{
	t_map	map;

	map = (t_map){0};
	if (ac == 2)
	{
		map_checker(&map, av[1]);
		map.mlx = mlx_init();
		map.win = mlx_new_window(map.mlx, map.x * PXL, map.y * PXL, "so_long");
		get_image(&map);
		pass_the_map(&map);
		mlx_key_hook(map.win, quit, &map);
		mlx_loop(map.mlx);
	}
	else
		ft_putstr_fd("\033[31m\\ERROR\n\033[0m", 2);
}	
