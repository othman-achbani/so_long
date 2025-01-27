/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 12:47:38 by oachbani          #+#    #+#             */
/*   Updated: 2025-01-27 12:47:38 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit(int keycode, s_var *var)
{
	if (keycode == ESC)
	{
		ft_putstr_fd("the ESC key is pressed the window will close now \n", 1);
		mlx_destroy_window(var->mlx, var->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == W)
		var->pos_y -= 10; 
	if (keycode == S)
		var->pos_y += 10;
	if (keycode == A)
		var->pos_x -= 10;
	if (keycode == D)
		var->pos_x += 10; 
}