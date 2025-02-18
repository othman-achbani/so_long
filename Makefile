NAME = so_long
BONUS_NAME = so_long_bonus

SRCS =	animation.c checkers.c errors.c \
       file_to_image.c main.c movement.c \
       moves.c player_info.c printmap.c

BONUS_SRCS = animation_bonus.c attack_bonus.c checkers_bonus.c \
             enemy_utils2_bonus.c enemy_utils_bonus.c errors_bonus.c \
             file_to_image2_bonus.c file_to_image_bonus.c \
             free2_bonus.c main_bonus.c movement_bonus.c \
             moves_bonus.c player_info_bonus.c \
             print_error_bonus.c printmap_bonus.c


OBJS = $(SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

RESET		=	'\033[0m'
GREEN		=	'\033[32m'
GRAY		=	'\033[2;37m'
ITALIC		=	'\033[3m'

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lX11 -lXext

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)
	@echo $(ITALIC)$(GRAY) "     - you game $(NAME) mandatory part is ready enjoy ..." $(RESET)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(BONUS_NAME)
	@echo $(ITALIC)$(GRAY) "     - you game bonus part is ready enjoy ..." $(RESET)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -sC $(LIBFT_DIR)

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@make -sC $(LIBFT_DIR) clean
	@echo $(ITALIC)$(GRAY) "     - deleting the files..." $(RESET)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make -sC $(LIBFT_DIR) fclean
	@echo $(ITALIC)$(GRAY) "     - deleting the game..." $(RESET)

re: fclean all

.PHONY: all bonus clean fclean re
.SECONDARY: