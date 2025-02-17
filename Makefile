# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 23:07:24 by oachbani          #+#    #+#              #
#    Updated: 2025/02/17 23:43:13 by oachbani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./mandatory/animation.c ./mandatory/checkers.c ./mandatory/errors.c ./mandatory/file_to_image.c\
		 ./mandatory/main.c ./mandatory/movement.c ./mandatory/moves.c ./mandatory/player_info.c ./mandatory/printmap.c 

SRCS_B =./bonus/animation_bonus.c ./bonus/attack_bonus.c ./bonus/checkers_bonus.c ./bonus/enemy_utils2_bonus.c\
		./bonus/free2_bonus.c ./bonus/main_bonus.c ./bonus/Makefile ./bonus/movement_bonus.c\
		./bonus/moves_bonus.c ./bonus/enemy_utils_bonus.c ./bonus/errors_bonus.c \
		./bonus/file_to_image2_bonus.c ./bonus/file_to_image_bonus.c ./bonus/player_info_bonus.c\
		./bonus/print_error_bonus.c ./bonus/printmap_bonus.c 

RM	= rm -f
CFLAGS = -Wall -Wextra -Werror
CC = cc
OBJF_B = $(SRCS_B:.c=.o)
OBJF = $(SRCS:.c=.o)
NAME = so_long
MLX = -lmlx -lX11 -lXext
libft = -L./libft -I./libft -lft
NAME_B = so_long_bonus

RESET		=	'\033[0m'
GREEN		=	'\033[32m'
GRAY		=	'\033[2;37m'
ITALIC		=	'\033[3m'

.c.o 	:
			@echo $(ITALIC)$(GREEN) "     - Compiling the file /$<..." $(RESET)
			@make -sC libft
			@$(CC) $(CFLAGS) -c $< -o $@

all  	:$(NAME)
bonus 	:$(NAME_B)

$(NAME_B): $(OBJF_B)
			@echo $(ITALIC)$(GRAY) "     - you game for the mandatory part is ready enjoy $(NAME_B) ..." $(RESET)
			@$(CC) $(CFLAGS) $(OBJF_B) $(libft) $(MLX) -o $(NAME_B)

$(NAME) : $(OBJF)
			@echo $(ITALIC)$(GRAY) "     - your game for the bonus part is ready enjoy $(NAME) ..." $(RESET)
			@$(CC) $(CFLAGS) $(OBJF) $(libft) $(MLX) -o $(NAME)
clean	: 
			@echo $(ITALIC)$(GRAY) "     - deleting the object files..." $(RESET)
			@make clean -sC libft
			@$(RM) $(OBJF) $(OBJF_B)

fclean	: clean
			@echo $(ITALIC)$(GRAY) "     - deleting the executable files..." $(RESET)
			@make fclean -sC libft
			@$(RM) $(NAME) $(NAME_B)

re		: fclean all

.PHONY	: all clean fclean re bonus 
.SECONDARY: