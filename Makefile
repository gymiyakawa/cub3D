
NAME = cub3d
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

####    DIRECTORIES    ####
SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj

####    MLX    ####
MLX_DIR = ./inc/MLX42/
MLX_CC = $(MLX_DIR)/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
MLX_GIT = https://github.com/codam-coding-college/MLX42.git
MLX_SUPP_FILE = ./suppresion/MLX42leak_suppresion.supp

####    LIBFT    ####
LIBFT_DIR = ./inc/libft/

####    FILES    ####
RAW_SRC = cub3d.c color_parsing.c init.c error.c map_parsing.c \
		print.c parsing_utils.c texture_parsing.c checks.c exit.c \
		mlx_control.c raycasting.c flood_fill.c map_parsing_2.c \

RAW_INC = cub3d.h structs.h

HEADERS = $(addprefix $(INC_DIR)/, $(RAW_INC))
SOURCES = $(addprefix $(SRC_DIR)/, $(RAW_SRC))
OBJECTS = $(addprefix $(OBJ_DIR)/, $(RAW_SRC:.c=.o))

####    COLORS    ####
GREEN	=	\033[0;32m
RESET	=	\033[0m
RED		=	\033[0;31m

####    RECIPES    ####
all: mlx $(NAME)

$(NAME): $(OBJECTS) | $(OBJ_DIR)
	@make -C $(LIBFT_DIR)

#	MacOs compilaion
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ $(OBJECTS) $(LIBFT_DIR)libft.a $(MLX_CC)

#	Linux compilation
#	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ $(OBJECTS) $(LIBFT_DIR)libft.a $(MLX_DIR)/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

#	WSL (Linux) compilation
#	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ $(OBJECTS) $(LIBFT_DIR)libft.a $(MLX_DIR)/build/libmlx42.a -Iinclude -ldl -lXext -lX11 -lm -pthread

	@echo "$(GREEN) cub3d compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

mlx:
	@if [ ! -d "$(INC_DIR)/MLX42" ]; then \
	git clone $(MLX_GIT) $(INC_DIR)/MLX42; \
	fi
	@if [ ! -d "$(INC_DIR)/MLX42/build" ]; then \
	cmake -B inc/MLX42/build inc/MLX42; \
	cmake --build inc/MLX42/build -j4; \
	echo "$(GREEN)\n MLX42 built and compiled successfully!$(RESET)"; \
	fi

clean:
	@rm -rf $(NAME) $(OBJ_DIR)
	@if [ -e valgrind.log ]; then rm valgrind.log; fi

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(MLX_DIR)
	@echo "$(RED)MLX42 folder deleted $(RESET)"
	@echo "$(RED)cub3d cleaned$(RESET)"

leak:
	make
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=$(MLX_SUPP_FILE) --log-file=valgrind.log ./cub3d ./maps/small.cub

run:
	@make
	@echo "testing with sample map"
	@echo ""
	@./cub3d ./maps/small.cub
	
re: fclean all

.PHONY: all clean fclean re leak run mlx
