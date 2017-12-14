# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 11:22:32 by jrasoloh          #+#    #+#              #
#    Updated: 2017/12/14 13:32:24 by jrasoloh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Werror -Wextra

CFLAGSPE = -lm -lmlx -framework OpenGL -framework Appkit

INCLUDE = includes/fractol.h

SRCS = srcs/main.c\
	   srcs/error.c\
	   srcs/display.c\
	   srcs/draw.c

OBJ = $(SRCS:.c=.o)

all : $(NAME) $(OBJ) $(SRCS)

$(NAME) : $(OBJ)
	make -C Libft
	make -C minilibx_macos
	gcc $(CFLAGS) $(CFLAGSPE) $(SRCS) Libft/libft.a minilibx_macos/libmlx.a -I$(INCLUDE) -o $(NAME)

clean :
	make clean -C Libft
	make clean -C minilibx_macos
	rm -f $(OBJ)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re
