# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 14:38:21 by hrothery          #+#    #+#              #
#    Updated: 2022/09/21 17:06:25 by hrothery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = 	src/main.c src/parser.c src/parser_utils.c src/parser_utils2.c \
		src/wall_check.c src/space_check.c src/parser_utils3.c

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a

CC = gcc

CFLAGS = #-Wall -Wextra -Werror

RM = rm -f

all : $(NAME)

ifeq ($(shell uname), Linux)

$(NAME):$(OBJ)
	make -C libft
	$(CC) $(OBJ) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz $(CFLAGS) $(LIB) -o $(NAME)

%o: %c 
	$(CC) $(CFLAGS) -I/usr/include -Imlx -03 -c $< -o $@

endif

ifeq ($(shell uname), Darwin)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework Appkit $(CFLAGS) $(LIB) -o $(NAME)

%o: %c 
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

endif

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME) 
	make fclean -C libft

re: fclean all 
