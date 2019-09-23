# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helamri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/27 16:59:05 by helamri           #+#    #+#              #
#    Updated: 2019/01/28 16:27:52 by helamri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

lib = libft/libft.a
NAME = fdf

all : $(NAME)

$(NAME) :
	@gcc -Wextra -Werror -Wall -c *.c 
	@ar rc $(NAME).a *.o
	@make -C libft/
	@gcc -Wextra -Werror -Wall -o $(NAME) $(NAME).c $(lib) $(NAME).a -lmlx -framework OpenGL -framework AppKit

clean :
	@make -C libft/ clean
	@/bin/rm -f *.o

fclean : clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f *.a

re : fclean all
	@make -C libft/ re
