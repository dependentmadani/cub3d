# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 12:16:05 by ael-asri          #+#    #+#              #
#    Updated: 2022/08/27 13:46:49 by ael-asri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = main.c\
		parsing/getMap.c\
		utils/utils.c\
		utils/utils2.c\
		utils/ft_split.c\
		utils/gnl/get_next_line.c\
		utils/gnl/get_next_line_utils.c\

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
