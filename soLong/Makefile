# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 13:25:14 by raruiz-r          #+#    #+#              #
#    Updated: 2022/12/12 12:22:19 by raruiz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS = so_long_bonus

SRCS = srcs/so_long.c srcs/check_input.c srcs/so_long_utils.c srcs/error.c \
		srcs/init_images.c srcs/valid_path.c srcs/moves.c

SRCS_B = bonus/so_long_bonus.c bonus/check_input_bonus.c bonus/error_bonus.c \
		bonus/init_images_bonus.c bonus/valid_path_bonus.c \
		bonus/moves_bonus.c bonus/so_long_utils_bonus.c bonus/anime_bonus.c

S = srcs/
B = bonus/
O = objs/
I = include/

OBJS = $(SRCS:$S%=$O%.o)

OBJS_B = $(SRCS_B:$B%=$O%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -I$I

RM = rm -f

RMDIR = rm -rf

MLX = -L./include/minilibx -lmlx -framework OpenGL -framework AppKit

GNL_SRCS = include/gnl/get_next_line.c include/gnl/get_next_line_utils.c

GNL_OBJS = ${GNL_SRCS:.c=.o}

FT_PRINTF = include/printf/libftprintf.a

FT_PRINTF_PATH = include/printf/

all: ${NAME}

$O:
	@mkdir $@

$(OBJS): | $O

$(OBJS): $O%.o: $S%
	@$(CC) $(CFLAGS) -c $< -o $@

$OB:
	@mkdir $@

$(OBJS_B): | $O

$(OBJS_B): $O%.o: $B%
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS} ${GNL_OBJS}
	${MAKE} -C ${FT_PRINTF_PATH}
	${CC} ${CFLAGS} ${MLX} ${OBJS} ${GNL_OBJS} ${FT_PRINTF}  -o $(NAME)

$(BONUS): ${OBJS_B} ${GNL_OBJS}
	${MAKE} -C ${FT_PRINTF_PATH}
	${CC} ${CFLAGS} ${MLX} ${OBJS_B} ${GNL_OBJS} ${FT_PRINTF}  -o $(BONUS)

cleanobj:
	@$(RM) $(wildcard $(OBJS)) $(wildcard $(OBJS_B))

cleanobjdir: cleanobj
	@$(RMDIR) $O
	
clean: cleanobjdir
	@make -C ${FT_PRINTF_PATH} clean


fclean:	clean
	${RM} ${NAME} $(BONUS) ${FT_PRINTF} 

bonus: $(BONUS) ${FT_PRINTF} 

re: fclean all

.PHONY: all clean fclean re
