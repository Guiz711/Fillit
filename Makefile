# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 15:56:40 by gmichaud          #+#    #+#              #
#    Updated: 2017/01/16 16:49:16 by gmichaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = get_next_line.c read_tetri.c ft_back.c solve.c ft_error.c \
		ft_notetri.c main.c

HEADER = get_next_line.h fillit.h

CC = clang

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) -Llibft -lft $^ -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean:
	/bin/rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f ./libft/libft.a

re: fclean $(NAME)
