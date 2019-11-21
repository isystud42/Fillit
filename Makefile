# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 12:43:28 by idsy              #+#    #+#              #
#    Updated: 2019/11/21 13:29:49 by idsy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##PROJECT FILLIT MAKEFILE

##COMPILER INFOS
NAME = fillit 
CC = gcc
CFLAGS = -Wall -Wextra -Wextra -g

##INCLUDES INFOS
HEADERS_PATH = ./
HEADERS_NAMES = fillit.h

##LIBS FILES INFOS
LIBS_FOLDER_PATH = ./
LIBS_NAMES = libft
LIB_HEADERS = libft/libft.h

##SOURCE FILES INFOS
SRCS_FILES = entry_checkers.c file_opening.c fillit.c grid_operations.c\
grid_printing.c parsing.c pieces_bit_operators.c entry_checkers_subfunctions.c
SRCS_PATHS = ./

##OBJECT FILES INFOS
OBJS_PATHS = objs/
OBJS_FILES = $(SRCS_FILES:.c=.o)

##VARS
#############FINISH THERE BEFORE CONTINUING 
HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_NAMES))
SRCS = $(addprefix $(SRCS_PATHS), $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATHS), $(OBJS_FILES))
LIBS = $(addprefix $(LIBS_FOLDER_PATH), $(LIBS_NAMES))
COMPILED_LIBS = $(addsuffix $(LIBS_NAMES).a, $(addsuffix /, $(LIBS)))
INCS = $(addprefix -I, $(HEADERS_PATH))
INC_LIBFT = $(addprefix -I, $(INC_LIBFT_PATH))

##RULES

all : $(NAME)

$(NAME) : $(COMPILED_LIBS) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(COMPILED_LIBS) $(OBJS)

$(COMPILED_LIBS) : $(LIBS)
	@make -C $<

$(OBJS_PATHS)%.o : $(SRCS_PATHS)%.c $(HEADERS) $(LIB_HEADERS) 
	@mkdir -p $(OBJS_PATHS)
	@$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "\033[32m█\033[0m\c"

$(LIBS) :
	@make -C $@

clean : 
	@make clean -C $(LIBS)
	@rm -rf $(OBJS_PATHS)

fclean : clean
	@make fclean -C $(LIBS)
	@rm -rf $(NAME)

re : fclean all

.PHONY : all re clean fclean
