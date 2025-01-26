/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-24 11:04:59 by oachbani          #+#    #+#             */
/*   Updated: 2025-01-24 11:04:59 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "./minilibx-linux/mlx.h"
#include "./libft/libft.h"
#include <stdio.h>

#define ESC 65307 
#define W 119
#define A 97
#define S 115
#define D 100


typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		pos_x;
	int		pos_y;
}				s_var;

#endif

