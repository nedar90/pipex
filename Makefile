# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 10:53:44 by nrajabia          #+#    #+#              #
#    Updated: 2023/04/03 10:53:47 by nrajabia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= pipex
BONUS		:= pipex_bonus
CC			:= cc
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -g3

HEADERS		:=  -I ./includes
LIBFT		:= $(shell find ./libft -iname "*.c")
OBJLIBFT	:= ${LIBFT:.c=.o}
SRCS		:= $(shell find ./src -iname "*.c")
OBJS		:= ${SRCS:.c=.o}
BONUS_SRC	:= $(shell find ./bonus -iname "*.c")
BONUS_OBJ	:= ${BONUS_SRC:.c=.o}

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\ "

$(NAME): $(OBJS) $(OBJLIBFT)
	@$(CC) $(OBJS) $(OBJLIBFT) $(HEADERS) -o $(NAME)

$(BONUS): $(BONUS_OBJ) $(OBJLIBFT)
	@$(CC) $(BONUS_OBJ) $(OBJLIBFT) $(HEADERS) -o $(BONUS)

all: $(NAME) $(BONUS)

bonus: $(BONUS)

clean:
	@rm -f $(OBJS) $(BONUS_OBJ) $(OBJLIBFT)

fclean: clean
	@rm -f $(NAME) $(BONUS)

re: clean all

.PHONY: all, clean, fclean, re
