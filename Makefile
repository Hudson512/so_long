# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 15:53:23 by hmateque          #+#    #+#              #
#    Updated: 2024/08/13 16:00:51 by hmateque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
#FLAGS = -Wall -Wextra -Werror

Libft_DIR = ./libft
Libft_A = $(Libft_DIR)/libft.a
Libix_DIR = ./mlx_linux
Libix_A = $(Libix_DIR)/libmlx.a
SRCS_DIR = ./src

SRCS =	main.c \
		$(SRCS_DIR)/checkers.c\
		$(SRCS_DIR)/get_next_line/get_next_line.c\
		$(SRCS_DIR)/get_next_line/get_next_line_utils.c


OBJ_SRC = $(SRCS:.c=.o)
OBJ_GET_NEXT_LINE = $(GET_NEXT_LINE:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ_SRC) $(Libix_A) $(Libft_A)
	$(CC) $(FLAGS) $(OBJ_SRC) $(Libft_A) $(OBJ_GET_NEXT_LINE) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(Libix_A):
	$(MAKE) -C $(Libix_DIR)

$(Libft_A):
	$(MAKE) -C $(Libft_DIR)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJ_SRC)
	$(MAKE) clean -C $(Libix_DIR)
	$(MAKE) clean -C $(Libix_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(Libft_DIR)

re: fclean all

.PHONY: all clean fclean re