# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 18:38:37 by aeloyan           #+#    #+#              #
#    Updated: 2022/11/19 14:05:28 by aeloyan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard *.c)
	  
OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a 

FLAGS = -Wall -Wextra -Werror

RM = rm -f

CC = cc

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	@$(MAKE) bonus -C ./libft
	@cp ./libft/libft.a .
	@$(MAKE) -C ./libft fclean
	@ar rcs libft.a $(OBJS)
	@mv libft.a $(NAME)

all:	$(NAME)

clean:
	@$(RM) $(OBJS) 
	
fclean: clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean re all
