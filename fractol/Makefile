# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helamri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/25 17:10:51 by helamri           #+#    #+#              #
#    Updated: 2019/05/05 20:28:15 by helamri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = utils.c color_and_pixel.c main.c init.c \
	  key_hook.c fractals.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FLAGSMLX = -L/usr/local/include -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

CC = gcc

INCLUDES = ./includes

LIBFT_PATH = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) -I$(INCLUDES) $(FLAGSMLX) $(LIBFT)

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

