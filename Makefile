# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 23:07:24 by oachbani          #+#    #+#              #
#    Updated: 2025/02/18 12:15:12 by oachbani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Compiler and flags
NAME = so_long
BONUS_NAME = so_long_bonus

MANDATORY = ./mandatory/animation.c ./mandatory/checkers.c ./mandatory/errors.c \
		  ./mandatory/file_to_image.c ./mandatory/main.c ./mandatory/movement.c \
		  ./mandatory/moves.c ./mandatory/player_info.c ./mandatory/printmap.c 

BONUS = ./bonus/animation_bonus.c ./bonus/attack_bonus.c ./bonus/checkers_bonus.c \
		  ./bonus/enemy_utils2_bonus.c ./bonus/free2_bonus.c ./bonus/main_bonus.c \
		  ./bonus/movement_bonus.c ./bonus/moves_bonus.c ./bonus/enemy_utils_bonus.c \
		  ./bonus/errors_bonus.c ./bonus/file_to_image2_bonus.c \
		  ./bonus/file_to_image_bonus.c ./bonus/player_info_bonus.c \
		  ./bonus/print_error_bonus.c ./bonus/printmap_bonus.c 

OBJ_MANDATORY = $(MANDATORY:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -lX11 -lXext

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SO_LONG_HEADER = ./mandatory/so_long.h
SO_LONG_BONUS_HEADER = ./bonus/so_long_bonus.h

all: $(LIBFT) $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT) $(OBJ_MANDATORY) $(SO_LONG_HEADER)
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(BONUS_NAME): $(LIBFT) $(OBJ_BONUS) $(SO_LONG_BONUS_HEADER)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ_MANDATORY)
	rm -f $(OBJ_BONUS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus