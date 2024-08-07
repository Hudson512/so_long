# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 15:53:23 by hmateque          #+#    #+#              #
#    Updated: 2024/08/07 17:05:27 by hmateque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
#FLAGS = -Wall -Wextra -Werror

Libix_DIR = ./mlx_linux
Libix_A = $(Libix_DIR)/libmlx.a

SRCS = main.c

OBJ_SRC = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ_SRC) $(Libix_A)
	$(CC) $(FLAGS) $(OBJ_SRC) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(Libix_A):
	$(MAKE) -C $(Libix_DIR)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJ_SRC)
	$(MAKE) clean -C $(Libix_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(Libix_DIR)

re: fclean all

.PHONY: all clean fclean re