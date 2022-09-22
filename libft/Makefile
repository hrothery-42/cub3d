# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 10:23:12 by hrothery          #+#    #+#              #
#    Updated: 2022/09/20 11:33:34 by hrothery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = libft.a
SRC = 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_double_free.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_striteri.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c \
		get_next_line_utils.c

OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

BONUS_OBJ = $(BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all = $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	
bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

clean: 
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean $(all)
