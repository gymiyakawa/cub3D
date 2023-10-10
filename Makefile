# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 09:58:15 by gmiyakaw          #+#    #+#              #
#    Updated: 2023/10/10 16:47:57 by gmiyakaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

####    LIBFT    ####
LIBFT_DIR = ./inc/libft/

####    FILES    ####
RAW_SRC = cub3d.c color_parsing.c
RAW_INC = cub3d.h structs.h

HEADERS = $(addprefix $(INC_DIR)/, $(RAW_INC))
SOURCES = $(addprefix $(SRC_DIR)/, $(RAW_SRC))
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

####    COLORS    ####

GREEN	=	\033[0;32m
RESET	=	\033[0m
RED		=	\033[0;31m

####    RECIPES    ####

all: mlx $(NAME)

$(NAME): $(OBJECTS) | $(OBJ_DIR)

	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ $(OBJECTS) $(LIBFT_DIR)libft.a $(MLX_CC)
	@echo "$(GREEN) cub3d compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)


mlx:
	@if [ ! -d "$(INC_DIR)/MLX42" ]; then \
	git clone $(MLX_GIT) $(INC_DIR)/MLX42; \
	fi
	cmake -B inc/MLX42/build inc/MLX42
	cmake --build inc/MLX42/build -j4 


clean:
	@rm -rf $(NAME) $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(MLX_DIR)
	@echo "$(RED)cub3d cleaned$(RESET)"

leaks:
	make re
	valgrind --leak-check=full --show-leak-kinds=all ./cub3d

run:
	make re
	./cub3d
	
re: fclean all

.PHONY: all clean fclean re leaks run mlx