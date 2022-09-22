# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 09:41:29 by bvarlamo          #+#    #+#              #
#    Updated: 2022/09/21 16:18:01 by bvarlamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


cub3D=	main.c keys.c raycastingHelpers.c helpers.c\

NAME	=	cub3

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

lib=./Libft

minilbx=./minilibx_opengl

FRAMEWORKS	=		-lmlx -framework OpenGL -framework AppKit -lz -L minilibx_opengl

INCLUDES	=		libft/libft.a minilibx_opengl/libmlx.a

cub3DO=	$(cub3D:.c=.o)

all :		$(NAME)

${NAME}:	${cub3DO}
		make -C ${lib}
		make -C ${minilbx}
		${CC} ${CFLAGS} ${cub3DO} $(INCLUDES) $(FRAMEWORKS) -o ${NAME}

clean :
	make clean -C ${lib}
	$(RM) ${cub3DO}

fclean :	clean
	$(RM) $(NAME)
	$(RM) $(cub3DO)
	make clean -C ${lib}
	make fclean -C ${lib}
	make clean -C ${minilbx}

re :		fclean all