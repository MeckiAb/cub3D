# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 23:58:48 by labderra          #+#    #+#              #
#    Updated: 2024/10/30 23:58:52 by labderra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
MLX42 = ./MLX42/build/libmlx42.a 
MLX_FLAGS = -Iinclude -ldl -lglfw -pthread -lm

SRC = main.c \

CC = clang -Wall -Wextra -Werror -g -fsanitize=address

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(MLX42)
	$(CC) $(OBJ) $(MLX42) $(MLX_FLAGS) -o $@

$(MLX42) :
	cmake -B MLX42/build -S ./MLX42
	cmake --build MLX42/build -j4

%.o : %.c
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
