# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 11:45:36 by ohladkov          #+#    #+#              #
#    Updated: 2023/10/15 14:52:53 by ohladkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_printf_utils.c ft_print_hex.c ft_print_ptr.c

NAME	= libftprintf.a

OBJS	= $(SRCS:.c=.o)

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

HEAD 	= ft_printf.h

all:		$(NAME)

$(NAME):	$(OBJS) 
		ar -rcs $(NAME) $(OBJS)

%.o: %.c	$(HEAD)
		$(CC) $(CFLAGS) -c -o $@ $<

clean:
		rm -f *.o

fclean:		clean
		rm -f $(NAME)

re:		fclean all
