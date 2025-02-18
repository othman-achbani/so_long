/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:45:31 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/18 18:17:56 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_checker(t_map *map, char *filename)
{
	map->y = 0;
	map->counter = 0;
	map->filename = filename;
	check_file(filename);
	get_tilesmap(map);
	check_lenmap(map);
	check_wall(map);
	content_counter(map);
	check_valid_path(map);
}

int	ft_close(t_map *map)
{
	ft_putstr_fd("you just pressed clos\
	e button it will close now\n", 1);
	ft_map_error(map, WINNER);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	map = (t_map){0};
	if (ac == 2)
	{
		map_checker(&map, av[1]);
		map.mlx = mlx_init();
		map.win = mlx_new_window(map.mlx, map.x * PXL, map.y * PXL, "so_long");
		scan_enemy(&map);
		get_image(&map);
		pass_the_map(&map, CLOSED);
		mlx_key_hook(map.win, quit, &map);
		mlx_hook(map.win, 17, 0, ft_close, &map);
		mlx_loop_hook(map.mlx, move_enemy, &map);
		mlx_loop(map.mlx);
	}
	else
		ft_putstr_fd("\033[31mError\n\033[0m", 2);
}
