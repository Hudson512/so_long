# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 11:30:39 by hmateque          #+#    #+#              #
#    Updated: 2024/05/28 13:54:08 by hmateque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRC			= 	ft_aux.c 		\
				ft_aux_function.c 		\
				ft_printf.c 	\
				ft_puthexadecimal.c 	\
				ft_putpointer.c 	\
				ft_putunsigned.c
OBJS 		= ${SRC:.c=.o}
LIBC 		= ar rcs
CC 			= cc
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror
${NAME}: ${OBJS}
			${LIBC} ${NAME} ${OBJS}
all: ${NAME}
clean:
			${RM} ${OBJS}
fclean: clean
			${RM} ${NAME}
re: fclean all
.PHONY : all clean fclean re
