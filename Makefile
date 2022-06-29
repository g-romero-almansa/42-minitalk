# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 13:59:41 by gromero-          #+#    #+#              #
#    Updated: 2022/05/23 14:13:18 by gromero-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_putchar.c ft_puthexa.c ft_putnbr.c ft_putnbr_hexa.c ft_putnnbr.c \
			ft_putstr.c ft_utils.c ft_printf.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

${NAME}:
		${CC} -c ${CFLAGS} ${SRCS}
		ar crs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
