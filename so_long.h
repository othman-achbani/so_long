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
#include <fcntl.h>
#include <stdio.h>

#define ESC 65307 
#define W 119
#define A 97
#define S 115
#define D 100
#define PXL 50

typedef struct s_vars
{
	char	*filename;
	void	*mlx;
	void	*win;
	int		pos_x;
	int		pos_y;
	void	*tile;
}				s_var;

typedef struct s_map
{
	char	*filename;
	void	*avatar;
	void	*avatar2;
	void	*avatar3;
	void	*wall;
	void	*door;
	void	*floor;
	void	*water;
	char	**tilesmap;
	char	*buffer;
	void	*coin;
	int		x;
	int		y;
	int		pos_x;
	int		pos_y;
	int		c;
	int		e;
	void	*mlx;
	void	*win;
}				t_map;

typedef struct s_data
{
	t_map *map;
	s_var var;
}				t_data;

void	check_file(t_map *map);
int		quit(int keycode, t_map *map);
void	get_image(t_map *map);
void	pass_the_map(t_map *map);
void	get_tilesmap(t_map *map);
void	map_checker(t_map *map , char *filename);
void	player_image(t_map *map);
void	find_player(t_map *map);
void	move_up(t_map *map);
void	content_counter(t_map *map);



#endif
