/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:23:20 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/12 19:40:36 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void destroyer(t_map *map)
{
	if (map->door)
        mlx_destroy_image(map->mlx, map->door);
    if (map->floor)
        mlx_destroy_image(map->mlx, map->floor);
    if (map->wall)
        mlx_destroy_image(map->mlx, map->wall);
    if (map->coin)
        mlx_destroy_image(map->mlx, map->coin);
    if (map->avatar)
        mlx_destroy_image(map->mlx, map->avatar);
    if (map->avatar2)
        mlx_destroy_image(map->mlx, map->avatar2);
    if (map->avatar3)
        mlx_destroy_image(map->mlx, map->avatar3);
	if (map->mlx && map->win)
	{
		mlx_destroy_window(map->mlx , map->win);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
}
void	ft_map_error(t_map *map, int pos)
{
	if (pos != WINNER)
	{
		ft_putstr_fd("\033[31mError\n\033[0m", 2);
		ft_putstr_fd(MAP_ERROR, 2);
	}
	destroyer(map);
	if (map->tilesmap)
		ft_free(map->tilesmap);
	if (map->copy)
		ft_free(map->copy);
	if (map->buffer)
		free(map->buffer);
	if (pos != WINNER)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

static void move_on_the_map(int x, int y, t_map *map)
{
	char t;
 
	t = map->copy[y][x];
    if (t == '1' || t == 'V')
        return;
    if (t == 'C')
        map->c_check--;
    else if (t == 'E')
	{
        map->e_check--;
		map->copy[y][x] = 'V';
		return ;
	}
	map->copy[y][x] = 'V';
    move_on_the_map(x + 1, y, map);
    move_on_the_map(x - 1, y, map);
    move_on_the_map(x, y + 1, map);
    move_on_the_map(x, y - 1, map);
}

void	check_valid_path(t_map *map)
{
	map->c_check = map->c;
	printf("%i",map->c_check );
	map->e_check = map->e;
	find_player(map);
	move_on_the_map(map->pos_x , map->pos_y, map);
	int i =0;
	while (map->copy[i])
	{
		printf("%s \n",map->copy[i]);
		i++;
	}
	printf("%i",map->c_check );
	if (map->c_check != 0 || map->e_check != 0)
		ft_map_error(map, 1);
}
