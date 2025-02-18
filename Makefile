NAME = so_long
BONUS_NAME = so_long_bonus

# Source files
SRCS =	animation.c checkers.c errors.c \
       file_to_image.c main.c movement.c \
       moves.c player_info.c mandatory/printmap.c

BONUS_SRCS = animation_bonus.c attack_bonus.c checkers_bonus.c \
             enemy_utils2_bonus.c enemy_utils_bonus.c errors_bonus.c \
             file_to_image2_bonus.c file_to_image_bonus.c \
             free2_bonus.c main_bonus.c movement_bonus.c \
             moves_bonus.c player_info_bonus.c \
             print_error_bonus.c printmap_bonus.c

# Object files
OBJS = $(SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lX11 -lXext

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

# Default target
all: $(NAME)

# Mandatory program
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

# Bonus program
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(BONUS_NAME)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean targets
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

# Ensure these targets always run
.PHONY: all bonus clean fclean re