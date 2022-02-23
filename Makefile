# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 13:06:54 by dgallo-p          #+#    #+#              #
#    Updated: 2022/02/22 12:10:23 by dgallo-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DG_HEAD = \_( ͠• ͜ʖ ͠• )_/\

GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[1;0m

NAME        = pipex

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

SRCS_SRCS   = ./sources/treat_argvs.c ./sources/error.c ./sources/free.c ./sources/path.c

SRCS_LIBFT  = ./sources/libft/ft_split.c ./sources/libft/ft_strncmp.c ./sources/libft/ft_strlen.c ./sources/libft/ft_strjoin.c

SRCS        = main.c $(SRCS_LIBFT) $(SRCS_SRCS)

OBJS		= $(SRCS:.c=.o)

all:        $(NAME)

$(NAME):    $(OBJS)
				@echo "$(BLUE) $(DG_HEAD) $(RESET)"
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo "$(BLUE)Compilating...$(RESET)"
				@echo "$(GREEN)$(NAME) created$(RESET)"

%.o: %.c
				@$(CC) $(CFLAGS) -c $< -o $@

norm:
				@norminette $(SRCS)

clean:
				@$(RM) $(OBJS)
				@echo "$(PURPLE)Deleting sources...$(RESET)"
				@echo "$(RED)$(NAME)/sources deleted$(RESET)\n"

fclean: clean
				@echo "$(PURPLE)Deleting pipex...$(RESET)"
				@echo "$(RED)$(NAME) deleted$(RESET)\n"
				@$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
