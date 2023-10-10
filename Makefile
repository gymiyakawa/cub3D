# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 09:58:15 by gmiyakaw          #+#    #+#              #
#    Updated: 2023/10/10 17:04:41 by raruiz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

####    DIRECTORIES    ####
SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj

####    LIBRARIES    ####
MLX_DIR = ./inc/mlx42/
LIBFT_DIR = ./inc/libft/

####    FILES    ####
RAW_SRC = cub3d.c color_parsing.c error.c map_parsing.c
RAW_INC = cub3d.h structs.h

HEADERS = $(addprefix $(INC_DIR)/, $(RAW_INC))
SOURCES = $(addprefix $(SRC_DIR)/, $(RAW_SRC))
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

####    COLORS    ####

GREEN	=	\033[0;32m
RESET	=	\033[0m
RED		=	\033[0;31m

####    RECIPES    ####

all: $(NAME)

$(NAME): $(OBJECTS) | $(OBJ_DIR) 
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ $(OBJECTS) $(LIBFT_DIR)libft.a 
	@echo "$(GREEN) cub3d compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(NAME) $(OBJ_DIR)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(RED)cub3d cleaned$(RESET)"

fclean: clean

leaks:
	make re
	valgrind --leak-check=full --show-leak-kinds=all ./cub3d

re: fclean all

.PHONY: all clean fclean re leaks