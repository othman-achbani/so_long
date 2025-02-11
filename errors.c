/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:23:20 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/11 17:16:51 by oachbani         ###   ########.fr       */
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
	if (map->mlx && map->win)
	{
		mlx_destroy_window(map->mlx , map->win);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	if (pos != WINNER)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
