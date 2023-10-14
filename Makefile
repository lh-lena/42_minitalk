# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 16:45:31 by ohladkov          #+#    #+#              #
#    Updated: 2023/10/14 19:51:05 by ohladkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS		= client.c server.c
SRCS_BNS	= client_bonus.c server_bonus.c

OBJS		:= $(SRCS:%.c=%.o)
OBJS_BNS	:= $(SRCS_BNS:%.c=%.o)

NAME	= minitalk
NAME_BNS = 

CC		= cc
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

all:		${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -Ilibft -Ift_printf -c $? -o $@

${NAME}:	 server client
# ${NAME_BNS}: server_bonus client_bonus

server:		server.o
		@make -C libft
		@make -C ft_printf
		${CC} ${CFLAGS} $? -Llibft -lft -Lft_printf -lftprintf -o server

server_bonus:		server_bonus.o
		@make -C libft
		@make -C ft_printf
		${CC} ${CFLAGS} $? -Llibft -lft -Lft_printf -lftprintf -o server_bonus

client:		client.o
		@make -C libft
		@make -C ft_printf
		${CC} ${CFLAGS} $? -Llibft -lft -Lft_printf -lftprintf -o client

client_bonus:		client_bonus.o
		@make -C libft
		@make -C ft_printf
		${CC} ${CFLAGS} $? -Llibft -lft -Lft_printf -lftprintf -o client_bonus

libft:
		make -C libft

printf:
		make -C ft_printf

# bonus:		${OBJS_BNS}
# 			${CC} ${CFLAGS} $(NAME) ${OBJS_BNS}

clean:
			make clean -C libft
			make clean -C ft_printf
			${RM} ${OBJS} ${OBJS_BNS}

fclean:		clean
			${RM} server client server_bonus client_bonus

re:			fclean all

bonus:	$(OBJS_BNS)
		@make all
		$(CC) $(CFLAGS) $(OBJS_BNS) -Llibft -lft -Lft_printf -lftprintf -o $(NAME_OBJ)

# bonus:		$(OBJS_BNS)
# 		$(RM) $(NAME) $(OBJS)
# 		@make -C libft
# 		@make -C ft_printf
# 		$(CC) $(CFLAGS) $(OBJS_BNS) -Llibft -lft -Lft_printf -lftprintf -o $(NAME_OBJ)

.PHONY:		all clean fclean re bonus libft ft_printf client_bonus server_bonus client server