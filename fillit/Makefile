# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmney <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 20:57:24 by hmney             #+#    #+#              #
#    Updated: 2018/11/13 21:52:30 by hmney            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = sources/*.c

OBJS = *.o

all: $(NAME)

$(NAME):
		@make -C libft/
		@gcc -o $(NAME) -Wall -Werror -Wextra $(SRCS) libft/libft.a

clean:
		@/bin/rm -f $(OBJS)
		@make clean -C libft/

fclean: clean
		@/bin/rm -f $(NAME)
		@make fclean -C libft/


re: fclean all
