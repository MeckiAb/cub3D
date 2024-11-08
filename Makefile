# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 23:58:48 by labderra          #+#    #+#              #
#    Updated: 2024/11/07 23:16:26 by labderra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT = libft/libft.a
MLX42 = ./MLX42/build/libmlx42.a 
MLX_FLAGS = -Iinclude -ldl -lglfw -pthread -lm

SRC = main.c \
initialize.c \
raycasting.c \
movement.c

CC = clang -Wall -Wextra -Werror -g -fsanitize=address

OBJ = $(SRC:.c=.o)

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
	make -C "libft" clean

fclean : clean
	rm -f $(NAME)
	make -C "libft" fclean

re : fclean all

.PHONY : all clean fclean re
