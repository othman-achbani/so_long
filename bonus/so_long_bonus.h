/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:04:59 by oachbani          #+#    #+#             */
/*   Updated: 2025/02/16 22:44:55 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define MAP_ERROR "\033[31mmap not valid please check the \
map and try again\n\033[0m"
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define PXL 64
# define F 102
# define WINNER 69
# define RIGHT 1
# define LEFT 0
# define NO_MAP 1
# define OPEN 1
# define CLOSED 0
#define VICTORY_MESSAGE "\033[1;92m" \
" ██╗   ██╗██╗ ██████╗████████╗ ██████╗ ██████╗ ██╗   ██╗\n" \
" ██║   ██║██║██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗╚██╗ ██╔╝\n" \
" ██║   ██║██║██║        ██║   ██║   ██║██████╔╝ ╚████╔╝ \n" \
" ╚██╗ ██╔╝██║██║        ██║   ██║   ██║██╔══██╗  ╚██╔╝  \n" \
"  ╚████╔╝ ██║╚██████╗   ██║   ╚██████╔╝██║  ██║   ██║   \n" \
"   ╚═══╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝   \n" \
"\033[0m"

#define GAME_OVER_MESSAGE "\033[1;91m" \
"  ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗ \n" \
" ██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗\n" \
" ██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝\n" \
" ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗\n" \
" ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║\n" \
"  ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝\n" \
"\033[0m"

#define MAP_ERROR_MESSAGE "\033[1;91m" \
" ███╗   ███╗ █████╗ ██████╗     ███████╗██████╗ ██████╗  ██████╗ ██████╗ \n" \
" ████╗ ████║██╔══██╗██╔══██╗    ██╔════╝██╔══██╗██╔══██╗██╔═══██╗██╔══██╗\n" \
" ██╔████╔██║███████║██████╔╝    █████╗  ██████╔╝██████╔╝██║   ██║██████╔╝\n" \
" ██║╚██╔╝██║██╔══██║██╔═══╝     ██╔══╝  ██╔══██╗██╔══██╗██║   ██║██╔══██╗\n" \
" ██║ ╚═╝ ██║██║  ██║██║         ███████╗██║  ██║██║  ██║╚██████╔╝██║  ██║\n" \
" ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝         ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝\n" \
"\033[0m"

typedef struct s_enemy {
    int x;       
    int y; 
	int direction; 
} 			t_enemy;

typedef struct s_map
{
	char	*filename;
	void	*avatar;
	void	*avatar2;
	void	*avatar3;
	void	*avatar_lft;
	void	*avatar2_lft;
	void	*avatar3_lft;
	void	*attack1_1;
	void	*attack1_2;
	void	*attack1_3;
	void	*attack1_1_lft;
	void	*attack1_2_lft;
	void	*attack1_3_lft;
	void	*shot;
	void	*enemy;
	void	*wall;
	void	*door;
	void	*door_closed;
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
	void	*shot_anim;
	void	*mlx;
	void	*win;
	int		counter;
	int		exit;
	int		c_check;
	int		e_check;
	int		direction;
	int		enemy_mv;
	int		enemy_nbr;
	void	*shot_lft;
	t_enemy	*enemy_pos;
	int		shot_count;
}			t_map;

void		remove_enemy(t_map *map, int x, int y);
int			dropfire_lft(t_map *map, int x, int y);
void		initialized(t_map *map);
void 		move_enemy_left(t_map *map, t_enemy **enemy);
void 		draw_enemy_position(t_map *map, int x, int y);
void 		clear_enemy_position(t_map *map, int x, int y);
void 		move_enemy_right(t_map *map, t_enemy **enemy);
void		scan_enemy(t_map *map);
void		ft_loser(t_map *map);
void		get_enemy_image(t_map *map);
int			move_enemy(t_map *map);
void		player_left_image(t_map *map);
void		enemy_counter(t_map *map);
void		destroyer_dir(t_map *map);
void		attack1(t_map *map);
void		print_moves(int num, t_map *map);
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
void		pass_the_map(t_map *map, int door);
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
void 		check_player_collision(t_map *map, int x, int y);
void 		update_position(t_map *map, int x, int y);
int			for_normadd_(t_map *map, int x, int y);
int			for_normmines_(t_map *map, int x, int y);

#endif
