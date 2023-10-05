# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 16:45:31 by ohladkov          #+#    #+#              #
#    Updated: 2023/10/05 14:47:34 by ohladkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Server
SERVER				=	server
SERVER_SRC			=	./server.c

SERVER_BONUS		=	server_bonus
SERVER_BONUS_SRC	=	./server_bonus.c

# Client
CLIENT				=	client
CLIENT_SRC			=	./client.c

CLIENT_BONUS		=	client_bonus
CLIENT_BONUS_SRC	=	./client_bonus.c

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

# Printf
PRINTF				=	libftprintf.a
PRINTF_SRC			=	./ft_printf/


# Compiler
CC					=	gcc
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