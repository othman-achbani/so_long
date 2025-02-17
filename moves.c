/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:47:38 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/17 14:49:56 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(int num)
{
	char	*line;

	line = ft_itoa(num);
	ft_putstr_fd("\033[1;36mthe number of moves is : \033[0m", 1);
	ft_putstr_fd(line, 1);
	ft_putstr_fd("\033[1;36m times.\n\033[0m", 1);
	free(line);
}

void	ft_winner(t_map *map)
{
	map->exit = 1;
	ft_putstr_fd("\033[93m  ▌ ▐·▪   ▄▄· ▄▄▄▄▄     \
▄▄▄   ▄· ▄▌    ▄▄ \n\033[0m", 1);
	ft_putstr_fd("\033[93m ▪█·█▌██ ▐█ ▌▪•██  ▪     \
▀▄ █·▐█▪██▌    ██▌ \n\033[0m", 1);
	ft_putstr_fd("\033[93m ▐█▐█•▐█·██ ▄▄ ▐█.▪ ▄█▀▄\
▐▀▀▄ ▐█▌▐█▪    ▐█· \n\033[0m", 1);
	ft_putstr_fd("\033[93m . ▀  ▀▀▀·▀▀▀  ▀▀▀  ▀█▄\
▀▪.▀  ▀  ▀ •      ▀  \n\033[0m", 1);
	ft_map_error(map, WINNER);
}

int	quit(int keycode, t_map *map)
{
	if (keycode == ESC)
	{
		ft_putstr_fd("the ESC key is pressed the window will close now \n", 1);
		ft_map_error(map, WINNER);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == W)
		move_up(map);
	else if (keycode == S)
		move_down(map);
	else if (keycode == A)
		move_left(map);
	else if (keycode == D)
		move_right(map);
	return (0);
}
