/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:16:21 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/14 10:35:11 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_image(t_map *map)
{
	int	px;

	px = PXL;
	map->door = mlx_xpm_file_to_image(map->mlx , \
"../utils_xpm/door.xpm", &px , &px);
	if (!map->door)
		ft_map_error(map, 1);
	map->floor = mlx_xpm_file_to_image(map->mlx , \
"../utils_xpm/stone_floor.xpm", &px, &px);
	if (!map->floor)
		ft_map_error(map, 1);
	map->wall = mlx_xpm_file_to_image(map->mlx , \
"../utils_xpm/wall.xpm", &px , &px);
	if (!map->wall)
		ft_map_error(map, 1);
	map->coin = mlx_xpm_file_to_image(map->mlx , \
"../utils_xpm/coin.xpm", &px, &px);
	if (!map->coin)
		ft_map_error(map, 1);
	player_image(map);
	player_left_image(map);
}

void	player_image(t_map *map)
{
	int	px;

	px = PXL;
	map->avatar = mlx_xpm_file_to_image(map->mlx, \
"../utils_xpm/avatarmv1.xpm", &px , &px);
	if (!map->avatar)
		ft_map_error(map, 1);
	map->avatar2 = mlx_xpm_file_to_image(map->mlx, \
"../utils_xpm/avatarmv2.xpm", &px , &px);
	if (!map->avatar2)
		ft_map_error(map, 1);
	map->avatar3 = mlx_xpm_file_to_image(map->mlx, \
"../utils_xpm/avatarmv3.xpm", &px , &px);
	if (!map->avatar3)
		ft_map_error(map, 1);
	map->attack1_1 = mlx_xpm_file_to_image(map->mlx, \
"../utils_xpm/attack1mv1.xpm", &px, &px);
	map->attack1_2 = mlx_xpm_file_to_image(map->mlx, \
"../utils_xpm/attack1mv2.xpm", &px, &px);
	if (!map->attack1_1 || !map->attack1_2)
		ft_map_error(map, 1);
	map->attack1_3 = mlx_xpm_file_to_image(map->mlx, \
"../utils_xpm/attack1mv3.xpm", &px, &px);
	if (!map->attack1_3)
		ft_map_error(map, 1);
}

void	player_left_image(t_map *map)
{
	int px;

	px = PXL;
	map->attack1_1_lft=mlx_xpm_file_to_image(map->mlx\
,"../utils_xpm/attack1mv1_left.xpm", &px, &px);
	map->attack1_2_lft=mlx_xpm_file_to_image(map->mlx\
,"../utils_xpm/attack1mv2_left.xpm", &px, &px);
	map->attack1_3_lft=mlx_xpm_file_to_image(map->mlx\
,"../utils_xpm/attack1mv3_left.xpm", &px, &px);
	if (!map->attack1_1_lft || !map->attack1_2_lft\
|| !map->attack1_3_lft)
		ft_map_error(map, 1);
	map->avatar_lft = mlx_xpm_file_to_image(map->mlx, \
"../utils_xpm/avatarmv1_left.xpm", &px, &px);
	map->avatar2_lft = mlx_xpm_file_to_image(map->mlx, \
"../utils_xpm/avatarmv2_left.xpm", &px, &px);
	map->avatar3_lft = mlx_xpm_file_to_image(map->mlx, \
"../utils_xpm/avatarmv3_left.xpm", &px, &px);
	if (!map->avatar_lft || !map->avatar2_lft\
|| !map->avatar3_lft)
		ft_map_error(map, 1);
}

void	ft_check_newline(char *line , t_map *map)
{
	if (line[0] == '\n')
	{
		free(line);
		ft_map_error(map, 1);
	}
}

void	get_tilesmap(t_map *map)
{
	char	*line;
	int		fd;
	char	*tmp;

	map->buffer = NULL;
	fd = open(map->filename , O_RDONLY);
	if (fd == -1)
		ft_map_error(map, NO_MAP);
	line = get_next_line(fd);
	if (!line)
		ft_map_error(map, NO_MAP);
	map->x = ft_strlen(line) - 1;
	while (line)
	{
		ft_check_newline(line, map);
		tmp = map->buffer;
		map->buffer = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
		map->y++;
	}
	close(fd);
	map->tilesmap = ft_split(map->buffer , '\n');
	map->copy = ft_split(map->buffer, '\n');
}
