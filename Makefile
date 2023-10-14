# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 16:45:31 by ohladkov          #+#    #+#              #
#    Updated: 2023/10/14 23:04:14 by ohladkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# NAMEC	= client
# NAMECB	= client_bonus

# NAMES	= server
# NAMESB	= server_bonus

# CC		= cc
# RM		= rm -f
# CFLAGS 	= -Wall -Wextra -Werror

# SRCS		= src/client.c src/server.c
# SRCS_BNS	= src/client_bonus.c src/server_bonus.c
		
# OBJS		:= $(SRCS:%.c=%.o)
# OBJS_BNS	:= $(SRCS_BNS:%.c=%.o)

# all:		$(NAMEC) $(NAMES)

# %.o:	%.c
# 		$(CC) $(CFLAGS) -Ilibft -Ift_printf -c $? -o $@

# $(NAMEC):	client
# $(NAMES):	server

# server:		server.o
# 		@make -C libft
# 		@make -C ft_printf
# 		$(CC) $(CFLAGS) $? -Llibft -lft -Lft_printf -lftprintf -o server

# server_bonus:	server_bonus.o
# 		@make -C libft
# 		@make -C ft_printf
# 		$(CC) $(CFLAGS) $? -Llibft -lft -Lft_printf -lftprintf -o server_bonus

# client:		client.o
# 		@make -C libft
# 		@make -C ft_printf
# 		$(CC) $(CFLAGS) $? -Llibft -lft -Lft_printf -lftprintf -o client

# client_bonus:	client_bonus.o
# 		@make -C libft
# 		@make -C ft_printf
# 		$(CC) $(CFLAGS) $? -Llibft -lft -Lft_printf -lftprintf -o client_bonus

# bonus:	$(NAMECB) $(NAMESB)

# $(NAMECB):	client_bonus
# $(NAMESB):	server_bonus

# libft:
# 		make -C libft

# printf:
# 		make -C ft_printf

# clean:
# 			make clean -C libft
# 			make clean -C ft_printf
# 			$(RM) $(OBJS) $(OBJS_BNS)

# fclean:		clean
# 			$(RM) server client server_bonus client_bonus

# re:			fclean all

# .PHONY:		all clean fclean re bonus

# Server
SERVER				=	server
SERVER_SRC			=	./src/server.c

SERVER_BONUS		=	server_bonus
SERVER_BONUS_SRC	=	./src/server_bonus.c

# Client
CLIENT				=	client
CLIENT_SRC			=	./src/client.c

CLIENT_BONUS		=	client_bonus
CLIENT_BONUS_SRC	=	./src/client_bonus.c

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

# Printf
PRINTF				=	libftprintf.a
PRINTF_SRC			=	./ft_printf/


# Compiler
CC					=	cc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra

# Rules
all:		$(LIBFT) $(PRINTF) $(SERVER) $(CLIENT)

bonus:		$(LIBFT) $(PRINTF) $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT):
			@make -C libft

$(PRINTF):
			@make -C ft_printf

$(SERVER):			$(SERVER_SRC)
					$(CC) $(CFLAGS) $(SERVER_SRC) $(PRINTF_SRC)$(PRINTF) $(LIBFT_SRC)$(LIBFT) -o $(SERVER)

$(SERVER_BONUS):	$(SERVER_BONUS_SRC)
					$(CC) $(CFLAGS) $(SERVER_BONUS_SRC) $(PRINTF_SRC)$(PRINTF) $(LIBFT_SRC)$(LIBFT) -o $(SERVER_BONUS)

$(CLIENT):			$(CLIENT_SRC)
					$(CC) $(CFLAGS) $(CLIENT_SRC) $(PRINTF_SRC)$(PRINTF) $(LIBFT_SRC)$(LIBFT) -o $(CLIENT)

$(CLIENT_BONUS):	$(CLIENT_BONUS_SRC)
					$(CC) $(CFLAGS) $(CLIENT_BONUS_SRC) $(PRINTF_SRC)$(PRINTF) $(LIBFT_SRC)$(LIBFT) -o $(CLIENT_BONUS)

clean:		
			$(RM) *.o $(CLIENT) $(SERVER) $(SERVER_BONUS) $(CLIENT_BONUS)

fclean:		clean
			@make -C libft fclean
			@make -C ft_printf fclean

re:			fclean all

.PHONY:		all clean fclean re bonus