/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:13:10 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/17 11:35:23 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(t_map *map)
{
	size_t	len;
	int		cmp;

	len = ft_strlen(map->filename);
	if (len < 5)
	{
		ft_putstr_fd("\033[31m map invalid it should end with .ber\n\033[0m", 2);
		exit(EXIT_FAILURE);
	}
	cmp = ft_strncmp(map->filename + (len - 4), ".ber", 4);
	if (cmp != 0)
	{
		ft_putstr_fd("\033[31m map invalid it should end with .ber\n\033[0m", 2);
		exit(EXIT_FAILURE);
	}
}

void	check_lenmap(t_map *map)
{
	int	len1;
	int	len2;
	int	i;

	if (!map->tilesmap)
	{
		ft_putstr_fd("\033[31m map not found \n\033[0m", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	len1 = ft_strlen(map->tilesmap[0]);
	while (map->tilesmap[++i])
	{
		len2 = ft_strlen(map->tilesmap[1]);
		if (len2 != len1)
		{
			ft_map_error(map, 1);
		}
	}
}

void	content_counter(t_map *map)
{
	int		x;
	int		y;
	int		p;

	map->c = 0;
	map->e = 0;
	y = -1;
	x = -1;
	p = 0;
	while(++y < map->y)
	{
		while (++x < map->x)
		{
			if (map->tilesmap[y][x] == 'C')
				map->c++;
			else if (map->tilesmap[y][x] == 'E')
				map->e++;
			else if (map->tilesmap[y][x] == 'P')
				p++;
		}
		x = -1;
	}
	if (map->e != 1 || p != 1 || map->c == 0)
		ft_map_error(map, NO_MAP);
}

void	check_wall(t_map *map)
{
	int	i;
	int y;

	i = -1;
	while (++i < map->x)
		if (map->tilesmap[0][i] != '1')
			ft_map_error(map, 1);
	i = -1;
	while (++i < map->y)
		if (map->tilesmap[i][0] != '1')
			ft_map_error(map, 1);
	i = map->x - 1;
	y = -1;
	while (++y < map->y )
		if (map->tilesmap[y][i] != '1')
			ft_map_error(map, 1);
	i = map->y - 1;
	y = -1;
	while (++y < map->x)
		if (map->tilesmap[i][y] != '1')
			ft_map_error(map, 1);
}
