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

// int main (int ac, char **av)
// {
// 	s_var	var;
// 	t_map	map;

// 	if (ac == 2)
// 	{
// 		map_checker(&map, av[1]);
// 		var.mlx = mlx_init();
// 		var.win = mlx_new_window(var.mlx, 900,600, "so_long");
// 		mlx_key_hook(var.win,quit, &var);
// 		get_image(&map, var);
// 		// pass_the_map(&map, var);
// 		mlx_loop(var.mlx);
// 	}
// 	else
// 		ft_putstr_fd("\033[31m\\ERROR\n\033[0m", 2);
// }	
int main(void)
{
    t_map map;

    map.filename = "map.ber";
    get_tilesmap(&map);

    // Print the tilesmap to verify
    for (int i = 0; i < map.y; i++)
    {
        printf("%s\n", map.tilesmap[i]);
    }

    // Free the tilesmap
    for (int i = 0; i < map.y; i++)
    {
        free(map.tilesmap[i]);
    }
    free(map.tilesmap);

    return 0;
}