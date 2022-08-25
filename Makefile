# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 12:16:05 by ael-asri          #+#    #+#              #
#    Updated: 2022/08/25 12:17:22 by ael-asri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) $(NAME)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re