# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 15:15:31 by jose-rig          #+#    #+#              #
#    Updated: 2024/11/08 14:15:36 by jose-rig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = parse
USER    = jose-rig
LIBFT   = Lib/Libft/
CFLAGS  = -g -Wall -Wextra -Werror -ILib -fsanitize=address
CC      = clang
LIB = -lreadline

SRCS	:= parse.c check_map_info.c check_map.c map_file_utils.c\
			init_free_utils.c check_map_utils.c


OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

$(NAME):	$(OBJS)
			make all -C $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LIB) -L$(LIBFT) -lft -o $(NAME)

$%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@make clean -C $(LIBFT)
			@rm -rf $(OBJS)
			
fclean:
			make fclean -C $(LIBFT)
			rm -rf $(OBJS)
			rm -rf $(NAME)

re: fclean all
				
.PHONY: all clean fclean re

