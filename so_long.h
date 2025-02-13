/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:04:59 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/13 16:59:10 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define PXL 64
# define MAP_ERROR "\033[31mmap not valid please check the \
map and try again\n\033[0m"
# define NO_MAP 2
# define NO_WIN 1
# define WINNER 69

typedef struct s_map
{
	char	*filename;
	void	*avatar;
	void	*avatar2;
	void	*avatar3;
	void	*wall;
	void	*door;
	void	*floor;
	char	**tilesmap;
	char	**copy;
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
	int		counter;
	int		exit;
	int		c_check;
	int		e_check;
}			t_map;

void		print_moves(int num);
void		animation_right(int x , int y , t_map *map);
void		animation_down(int x , int y , t_map *map);
void		animation_up(int x , int y , t_map *map);
void		animation_left(int x , int y , t_map *map);
void		check_valid_path(t_map *map);
void		check_wall(t_map *map);
void		destroyer(t_map *map);
void		check_file(t_map *map);
int			quit(int keycode, t_map *map);
void		get_image(t_map *map);
void		pass_the_map(t_map *map);
void		get_tilesmap(t_map *map);
void		map_checker(t_map *map, char *filename);
void		player_image(t_map *map);
void		find_player(t_map *map);
void		move_up(t_map *map);
void		content_counter(t_map *map);
void		move_right(t_map *map);
void		move_left(t_map *map);
void		move_down(t_map *map);
void		check_lenmap(t_map *map);
void		content_counter(t_map *map);
void		ft_winner(t_map *map);
void		ft_map_error(t_map *map, int pos);

#endif
