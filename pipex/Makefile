# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helamri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 14:09:09 by helamri           #+#    #+#              #
#    Updated: 2019/02/03 20:42:36 by helamri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			pipex

CFILE =			main.c					\
				ft_exist.c

OBJ =			$(CFILE:.c=.o)

AFILE =			./libft/libft.a

LIBMAKE =		@make -C libft/

all:			$(NAME)

$(NAME):		$(OBJ)
	$(LIBMAKE)
	@gcc -Wall -Wextra -Werror -I ./libft/includes/ -o $(NAME) $(OBJ) $(AFILE)

clean:
	@rm -f $(OBJ)

fclean:			clean
	@rm -f $(NAME)
	$(LIBMAKE) fclean

re:				fclean all

lib_all:
	$(LIBMAKE)

lib_clean:
	$(LIBMAKE) clean

lib_fclean:
	$(LIBMAKE) fclean

lib_re:
	$(LIBMAKE) re

%.o:			%.c
	@gcc -Wall -Wextra -Werror -I ./libft/includes/ -c main.c -o main.o
	@gcc -Wall -Wextra -Werror -I ./libft/includes/ -c ft_exist.c -o ft_exist.o
