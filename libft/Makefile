# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helamri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 17:18:29 by helamri           #+#    #+#              #
#    Updated: 2018/10/11 16:38:44 by helamri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS=*.c 

OBJS=*.o

all:	$(NAME)

$(NAME):	$(SRCS) libft.h
		@gcc -c -Wall -Wextra -Werror $(SRCS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
clean:
	    @/bin/rm -f $(OBJS)

fclean:	clean
	    @/bin/rm -f $(NAME)

re:	fclean all
