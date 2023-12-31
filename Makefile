
NAME = cub3D
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
RAW_SRC = cub3d.c color_parsing.c init.c init_2.c exit.c map_parsing.c 	\
		print.c parsing_utils.c  parsing_utils_2.c texture_parsing.c	\
		checks.c exit_2.c mlx_control.c raycasting.c flood_fill.c 		\
		map_parsing_2.c raycasting_init.c texture_rendering.c moves.c	\
		texture_parsing2.c

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

valgrind:
	@make
	@echo "\n	<!> ATTENTION <!>\n"
	@echo "To run valgrind, all funcitons inside of (parsing(av[1], ms)) must be commented out\n"
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=$(MLX_SUPP_FILE) --log-file=valgrind.log ./cub3d ./maps/15_extraelement.cub

leak:
	@make
	leaks --atExit -- ./$(NAME) maps/42.cub

tester:
	@bash maptester.sh

run:
	@make
	@echo "testing with 42.cub"
	@echo ""
	@./$(NAME) ./maps/42.cub
	
bunker:
	@make
	@echo "testing with bunker.cub"
	@echo ""
	@./$(NAME) ./maps/bunker.cub
	
re: fclean all

bonus:
	@echo "no bonus for this project"
	@echo "try make run or make bunker"

.PHONY: all clean fclean re leak run mlx valgrind bunker bonus
