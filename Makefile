# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 23:58:48 by labderra          #+#    #+#              #
#    Updated: 2024/11/16 19:06:01 by jose-rig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT = libft/libft.a
MLX42 = ./MLX42/build/libmlx42.a 
MLX_FLAGS = -Iinclude -ldl -lglfw -pthread -lm

SRC = main.c \
initialize.c \
raycasting.c \
movement.c \
_parse.c \
_check_map_info.c _check_map_utils.c  _check_map_ut_2.c _check_map.c \
_map_file_utils.c _init_free_utils.c \
_utilities.c

SRC_BONUS = main_bonus.c \
initialize_bonus.c \
raycasting_bonus.c \
movement_bonus.c

CC = clang -Wall -Wextra -Werror -g -fsanitize=address

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(MLX42)
	$(CC) $(OBJ) $(LIBFT) $(MLX42) $(MLX_FLAGS) -o $@

$(LIBFT) :
	make -C "libft"

$(MLX42) :
	cmake -B MLX42/build -S ./MLX42
	cmake --build MLX42/build -j4

%.o : %.c
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	make -C "libft" clean

fclean : clean
	rm -f $(NAME)
	make -C "libft" fclean

re : fclean all

bonus : $(OBJ_BONUS) $(LIBFT) $(MLX42)
	$(CC) $(OBJ_BONUS) $(LIBFT) $(MLX42) $(MLX_FLAGS) -o $(NAME)

.PHONY : all clean fclean re
