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
	int	px;

	px = PXL;
	map->door = mlx_xpm_file_to_image(var.mlx , "./utils_xpm/door.xpm", &px , &px);
	map->floor = mlx_xpm_file_to_image(var.mlx , "./utils_xpm/stone_floor.xpm", &px, &px);
	map->wall = mlx_xpm_file_to_image(var.mlx , "./utils_xpm/wall.xpm", &px , &px);
	map->coin = mlx_xpm_file_to_image(var.mlx , "./utils_xpm/coin.xpm", &px , &px);
	player_image(map, var);
}

void	player_image(t_map *map , s_var var)
{
	int	px;

	px = PXL;	
	map->avatar = mlx_xpm_file_to_image(var.mlx , "./utils_xpm/avatarmv1.xpm", &px , &px);
	map->avatar2 = mlx_xpm_file_to_image(var.mlx , "./utils_xpm/avatarmv2.xpm", &px , &px);
	map->avatar3 = mlx_xpm_file_to_image(var.mlx , "./utils_xpm/avatarmv3.xpm", &px , &px);
	
}

void	get_tilesmap(t_map *map)
{
	char	*line;
	int		fd;

	map->y = 0;
	map->buffer = "";
	fd = open(map->filename , O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("can't open file\n", 2);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	map->x = ft_strlen(line);
	while (line)
	{
		map->buffer = ft_strjoin(map->buffer, line);
		free(line);
		line = get_next_line(fd);
		map->y++;
	}
	close (fd);
	map->tilesmap = ft_split(map->buffer , '\n');
}