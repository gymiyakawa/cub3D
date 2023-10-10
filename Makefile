# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 09:58:15 by gmiyakaw          #+#    #+#              #
#    Updated: 2023/10/10 12:30:02 by gmiyakaw         ###   ########.fr        #
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
RAW_SRC = cub3d.c
RAW_INC = defs.h

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

fclean: clean

leaks:
	make re
	valgrind --leak-check=full --show-leak-kinds=all ./cub3d

re: fclean all

.PHONY: all clean fclean re leaks