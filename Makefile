# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 12:16:05 by ael-asri          #+#    #+#              #
#    Updated: 2022/08/28 10:28:42 by ael-asri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = main.c\
		parsing/getMap.c\
		parsing/checkMap.c\
		utils/utils.c\
		utils/utils2.c\
		utils/ft_split.c\
		utils/gnl/get_next_line.c\
		utils/gnl/get_next_line_utils.c\
		window/starter.c\
		window/create_window.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -Imlx

all : $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
