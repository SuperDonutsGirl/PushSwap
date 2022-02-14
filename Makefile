# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 13:54:35 by pamartin          #+#    #+#              #
#    Updated: 2022/02/07 13:54:37 by pamartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 		push_swap
### FILES
SRC			=		push_swap.c \
					mvt_push.c		mvt_swap.c		mvt_reverse.c		mvt_rotate.c \
					utils.c			utils_found.c  utils_mvt.c	utils_binaire.c utils_sort_4.c\
					sort_little.c 	sort_quick.c	sort_radix.c sort_extraction.c 

OBJ			= 		$(SRC:.c=.o)


### COMMANDS
CC			=		gcc
FLAGS		=		-Wall -Wextra -Werror
RM			=		rm -rf


### NAME
$(NAME)		:		$(OBJ)
	$(CC) -o $(NAME) $(OBJ)


### RULES
all			:		$(NAME)
clean		:
	$(RM) $(OBJ)
fclean		:		clean
	$(RM) $(NAME)
re			:		fclean all

