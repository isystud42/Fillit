# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 23:06:48 by mbouanik          #+#    #+#              #
#    Updated: 2017/01/06 12:58:14 by mbouanik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = 	fillit.c\
		ft_placement.c\
		parseur.c\
		parseur2.c\
		parseur3.c\
		ft_binary.c


OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra
LIB_PATH = -L libft/
LIB = -lft
INC = -I includes/
INC_LIBFT = -I libft/

all : $(NAME)

$(NAME) : libft $(OBJ)
	@$(CC) $(LIB_PATH) $(LIB) -o $@ $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) $(INC_LIBFT) -o $@ -c $<
	@echo "\033[32m█\033[0m\c"

libft :
	@make -C libft/

clean :
	make clean -C libft/
	rm -f $(OBJ)

fclean : clean
	make fclean -C libft/
	rm -f $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re, libft
