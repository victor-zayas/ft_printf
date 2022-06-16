# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 11:43:07 by vzayas-s          #+#    #+#              #
#    Updated: 2022/06/16 12:02:57 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDE = ft_printf.h

SRC = ft_printf.c ft_printf_utils.c

OBJ = $(SRC:.c=.o)

CC = gcc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

all: $(NAME)

$(NAME) : $(OBJ) $(INCLUDES)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(COLOUR_GREEN)library created$(COLOUR_END)"

$(OBJ) : $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC)

clean:
	@$(RM) $(OBJ) $(BONUS_OBJS)
	@echo "$(COLOUR_RED)objs deleted$(COLOUR_END)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOUR_RED)executable deleted$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re bonus
