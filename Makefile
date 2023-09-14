# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brmajor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 16:28:06 by brmajor           #+#    #+#              #
#    Updated: 2023/08/30 12:50:38 by brmajor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_S = src/server.c inc/minitalk.h

SRC_C = src/client.c inc/minitalk.h

CC = gcc -g -Wall -Werror -Wextra

NAME_S = server

NAME_C = client

$(NAME_S): src/server.c inc/minitalk.h
	make -C libft/
	$(CC) $(SRC_S) -L libft -l ft -o $(NAME_S)

$(NAME_C): src/client.c inc/minitalk.h
	$(CC) $(SRC_C) -L libft -l ft -o $(NAME_C)

all: $(NAME_S) $(NAME_C)

clean:
	make -C libft/ fclean

fclean: clean
	rm -rf $(NAME_S) $(NAME_C)

re: fclean all

.PHONY: all clean fclean re
