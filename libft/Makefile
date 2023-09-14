# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brmajor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 14:18:09 by brmajor           #+#    #+#              #
#    Updated: 2023/08/01 14:52:32 by brmajor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	libft_str/ft_atoi.c \
	libft_str/ft_bzero.c \
        libft_str/ft_calloc.c \
        libft_str/ft_isalnum.c \
        libft_str/ft_isalpha.c \
        libft_str/ft_isascii.c \
        libft_str/ft_isdigit.c \
        libft_str/ft_isprint.c \
        libft_str/ft_itoa.c \
        libft_str/ft_memchr.c \
        libft_str/ft_memcmp.c \
       	libft_str/ft_memcpy.c \
        libft_str/ft_memmove.c \
        libft_str/ft_memset.c \
        libft_fd/ft_putchar_fd.c \
        libft_fd/ft_putendl_fd.c \
        libft_fd/ft_putnbr_fd.c \
        libft_fd/ft_putstr_fd.c \
        libft_str/ft_split.c \
        libft_str/ft_strchr.c \
        libft_str/ft_strdup.c \
        libft_str/ft_striteri.c \
        libft_str/ft_strjoin.c \
        libft_str/ft_strlcat.c \
        libft_str/ft_strlcpy.c \
        libft_str/ft_strlen.c \
        libft_str/ft_strmapi.c \
        libft_str/ft_strncmp.c \
        libft_str/ft_strnstr.c \
        libft_str/ft_strrchr.c \
        libft_str/ft_strtrim.c \
        libft_str/ft_substr.c \
        libft_str/ft_tolower.c \
        libft_str/ft_toupper.c \
	ft_printf/ft_printf.c ft_printf/putcharf.c ft_printf/putdecf.c ft_printf/puthexf.c ft_printf/putnbrf.c ft_printf/putptrf.c ft_printf/putstrf.c ft_printf/utils.c \
	get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c error_handler.c\


BONUS_SRC =	libft_lists/ft_lstnew.c \
		libft_lists/ft_lstadd_front.c \
		libft_lists/ft_lstsize.c \
		libft_lists/ft_lstlast.c \
		libft_lists/ft_lstadd_back.c \
		libft_lists/ft_lstdelone.c \
	    	libft_lists/ft_lstclear.c \
		libft_lists/ft_lstiter.c \
		libft_lists/ft_lstmap.c \
		$(SRC)

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_DIR), $(BONUS_SRC:.c=.o))
CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a

$(OBJ_DIR)%.o: %.c libft.h
	@mkdir -p $(@D)
	@gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar r $@ $^ 2> /dev/null
	@echo $(NAME) created
	@echo Compilation completed

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) -c $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f *.o
	@echo Object files removed

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) removed

bonus:	$(BONUS_OBJ) $(NAME)
	@ar r $(NAME) $(BONUS_OBJ)
	@echo $(NAME) updated with bonus functions

re: fclean all

.PHONY: all clean fclean re
