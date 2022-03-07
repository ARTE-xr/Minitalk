# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mattif <mattif@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 16:15:59 by mattif            #+#    #+#              #
#    Updated: 2022/03/01 16:16:09 by mattif           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server

NAME2 = client

CC = gcc

INC = minitalk_bonus.h

CFLAGS = -Wall -Wextra -Werror

SOURCES =	minitalk_utils.c\

OBJECTS = $(SOURCES:.c=.o) 

all:$(NAME1) $(NAME2)

$(NAME1) : server.c $(INC)
	 		$(CC) $(CFLAGS) server.c $(SOURCES) -o server
$(NAME2) : client.c $(INC)
			$(CC) $(CFLAGS) client.c $(SOURCES) -o client
clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME1) $(NAME2)

re: fclean all