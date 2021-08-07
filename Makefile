# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 15:53:17 by ioleinik          #+#    #+#              #
#    Updated: 2021/08/07 15:34:03 by ioleinik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

NAME		= philo

MAKE		= make

SRC			= main.c check_contract.c

OBJ			= ${SRC:.c=.o}

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -I. $(CFLAGS) -o $(NAME) $(OBJ)

clean:		
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re