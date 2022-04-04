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
N_BONUS		=		checker

### DIRECTORY
SOURCE 		= 		./src/
HEADER		= 		./include/
GNL 		=		../gnl/
BONUS_SRC	=		./bonus/

### FILES
SRC			=		push_swap.c \
					mvt_push.c			mvt_swap.c				mvt_reverse.c			mvt_rotate.c \
					utils.c				utils_found.c   		utils_check.c 			utils_split.c 	utils_check_params.c\
					sort_little.c 		sort_quick.c			sort_radix.c 			sort_extraction.c 

OBJ			= 		$(addprefix $(SOURCE), $(SRC:.c=.o))

SRC_GNL		=		$(GNL)get_next_line.c		$(GNL)get_next_line_utils.c 

SRC_BONUS	=		checker.c \
					utils_bonus.c		utils_check_bonus.c 	utils_split_bonus.c \
					mvt_push_bonus.c 	mvt_reverse_bonus.c 	mvt_rotate_bonus.c 		mvt_swap_bonus.c \
					$(SRC_GNL)

OBJ_BONUS	=		$(addprefix $(BONUS_SRC), $(SRC_BONUS:.c=.o))


### COMMANDS
CC			=		gcc
FLAGS		=		-Wall -Wextra -Werror 
INCLUDE		= 		-I $(HEADER)
RM			=		rm -rf


### NAME
$(NAME)		:		$(OBJ)
	$(CC) $(FLAGS) $(INCLUDE) -o $(NAME) $(OBJ)
$(N_BONUS)	:		$(OBJ_BONUS)
	$(CC) $(FLAGS) $(INCLUDE) -o $(N_BONUS) $(OBJ_BONUS)


### RULES
all			:		$(NAME)
bonus 		:		$(N_BONUS)
clean		:
	$(RM) $(OBJ) $(OBJ_BONUS)
fclean		:		clean
	$(RM) $(NAME) $(N_BONUS)
re			:		fclean all

