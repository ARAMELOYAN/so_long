# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 11:19:42 by aeloyan           #+#    #+#              #
#    Updated: 2022/11/19 14:05:19 by aeloyan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)

SRCS_B = ft_lstnew.c \
		 ft_lstadd_front.c \
		 ft_lstsize.c \
		 ft_lstlast.c \
		 ft_lstadd_back.c \
		 ft_lstdelone.c \
		 ft_lstclear.c \
		 ft_lstiter.c \
		 ft_lstmap.c

OBJS_B = $(SRCS_B:.c=.o)

NAME = libft.a 

FLAGS = -Wall -Wextra -Werror

RM = rm -f

CC = cc

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

all:	$(NAME)

bonus:		$(OBJS) $(OBJS_B) libft.h
	@ar rcs $(NAME) $(OBJS) $(OBJS_B)

clean:
	@$(RM) $(OBJS) $(OBJS_B)
	
fclean: clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean bonus re all
