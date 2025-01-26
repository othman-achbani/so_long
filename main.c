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

int	quit(int keycode, s_var *var)
{
	if (keycode == ESC)
	{
		ft_putstr_fd("the ESC key is pressed the window will close now \n", 1);
		mlx_destroy_window(var->mlx, var->win);
		exit(EXIT_SUCCESS);
	}
}

int main ()
{
	s_var	var;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 900,600, "so_long");
	mlx_key_hook(var.win,quit, &var);
	mlx_loop(var.mlx);
}