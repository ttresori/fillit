# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 18:23:16 by carmand           #+#    #+#              #
#    Updated: 2017/09/30 20:06:55 by ttresori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc 

FLAGS = -Wall -Werror -Wextra

LIB = ./libft/libft.a

SRC =	 	main.c \
			def_list.c \
			def_tetri.c \
			verif_list.c \
			verif_tetri.c \
			algo_tetri.c \
			free_fillit.c \
			try_to_fill.c \
			find_order.c \
			init.c \
			redux_fill.c 

OBJ = $(SRC:.c=.o)
	

all: $(NAME)

$(NAME): $(LIB)
	$(CC) $(FLAGS) -c $(SRC) -I . -I ./libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L ./libft -lft  

$(LIB):
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean all

.PHONY : clean all re fclean
