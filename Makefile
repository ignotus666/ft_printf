# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/02 10:27:19 by dahanlon          #+#    #+#              #
#    Updated: 2026/10/02 15:40:41 by dahanlon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = 

OBJ = ${FILES:.c=.o}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .

%.o:%.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

$(NAME): ${OBJ}
		ar rcs ${NAME} ${OBJ}

all:	${NAME}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re