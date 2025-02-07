/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-24 15:45:31 by oachbani          #+#    #+#             */
/*   Updated: 2025-01-24 15:45:31 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checker(t_map *map , char *filename)
{
	map->filename = filename;
	check_file(map);
	get_tilesmap(map);
}

int main (int ac, char **av)
{
	s_var	var;
	t_map	map;

	if (ac == 2)
	{
		map_checker(&map, av[1]);
		map.mlx = mlx_init();
		map.win = mlx_new_window(map.mlx, 1900,600, "so_long");
		get_image(&map);
		pass_the_map(&map);
		mlx_key_hook(map.win, quit, &map);
		mlx_loop(map.mlx);
	}
	else
		ft_putstr_fd("\033[31m\\ERROR\n\033[0m", 2);
}	
