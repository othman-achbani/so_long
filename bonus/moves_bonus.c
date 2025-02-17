/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:47:38 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/17 17:13:50 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_moves(int num, t_map *map)
{
	char	*line;

	line = ft_itoa(num);
	mlx_put_image_to_window(map->mlx, map->win, map->wall, PXL, 0);
	mlx_put_image_to_window(map->mlx, map->win, map->wall, PXL * 2, 0);
	mlx_string_put(map->mlx, map->win, PXL + 20, 32, 0xffffff, "MOVES:");
	mlx_string_put(map->mlx, map->win, PXL * 2, 32, 0x00ff00, line);
	free(line);
}

void	ft_loser(t_map *map)
{
	game_over_message();
	ft_map_error(map, WINNER);
}

void	ft_winner(t_map *map)
{
	victory_message();
	ft_map_error(map, WINNER);
}

int	quit(int keycode, t_map *map)
{
	if (keycode == ESC)
	{
		ft_putstr_fd("the ESC key is pressed the window will close now \n", 1);
		ft_map_error(map, WINNER);
	}
	else if (keycode == W)
		move_up(map);
	else if (keycode == S)
		move_down(map);
	else if (keycode == A)
		move_left(map);
	else if (keycode == D)
		move_right(map);
	else if (keycode == F)
		attack1(map);
	return (0);
}
