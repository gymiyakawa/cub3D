# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 09:58:15 by gmiyakaw          #+#    #+#              #
#    Updated: 2023/10/10 10:21:45 by gmiyakaw         ###   ########.fr        #
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
MLX_DIR = ./MLX42/mlx42/
LIBFT_DIR = ./libft/

$(LIBS) = -I $(MLX_DIR)libmlx42.a -I $(LIBFT_DIR)libft.a 

####    FILES    ####
RAW_SRC = cub3d.cpp 
RAW_INC = 

HEADERS = $(addprefix $(INC_DIR)/, $(RAW_INC))
SOURCES = $(addprefix $(SRC_DIR)/, $(RAW_SRC))
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)


all: $(NAME)

$(NAME): $(OBJECTS) | $(OBJ_DIR) 
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ $(OBJECTS) $(LIBS)
	@echo "compiled!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(NAME) $(OBJ_DIR)

fclean: clean

leaks:
	make re
	valgrind --leak-check=full --show-leak-kinds=all ./cub3d

re: fclean all

.PHONY: all clean fclean re leaks