# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 11:53:32 by ohladkov          #+#    #+#              #
#    Updated: 2023/10/25 19:20:46 by ohladkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRS_DIR 			= ./src

# Server
SERVER				=	server
S_SRC				=	$(SRS_DIR)/server.c
S_OBJ				=	$(S_SRC:.c=.o)

SERVER_BONUS		=	server_bonus
S_BNS_SRC			=	$(SRS_DIR)/server_bonus.c
S_BNS_OBJ			=	$(S_BNS_SRC:.c=.o)

# Client
CLIENT				=	client
C_SRC				=	$(SRS_DIR)/client.c
C_OBJ				=	$(C_SRC:.c=.o)

CLIENT_BONUS		=	client_bonus
C_BNS_SRC			=	$(SRS_DIR)/client_bonus.c
C_BNS_OBJ			=	$(C_BNS_SRC:.c=.o)

# Libft library
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

# Printf library
PRINTF				=	libftprintf.a
PRINTF_SRC			=	./ft_printf/

# Compiler
CC					=	cc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra

# Targets
all:		$(LIBFT) $(PRINTF) $(SERVER) $(CLIENT)

bonus:		$(LIBFT) $(PRINTF) $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT):
			@make -C $(LIBFT_SRC)

$(PRINTF):
			@make -C $(PRINTF_SRC)

$(SERVER):	$(S_OBJ)
	$(CC) $(CFLAGS) $(S_SRC) -o $(SERVER) $(PRINTF_SRC)$(PRINTF) $(LIBFT_SRC)$(LIBFT)

$(SERVER_BONUS):	$(S_BNS_OBJ)
	$(CC) $(CFLAGS) $(S_BNS_SRC) -o $(SERVER_BONUS) $(PRINTF_SRC)$(PRINTF) $(LIBFT_SRC)$(LIBFT)

$(CLIENT):	$(C_OBJ)
	$(CC) $(CFLAGS) $(C_SRC) -o $(CLIENT) $(PRINTF_SRC)$(PRINTF) $(LIBFT_SRC)$(LIBFT)

$(CLIENT_BONUS):	$(C_BNS_OBJ)
	$(CC) $(CFLAGS) $(C_BNS_SRC) -o $(CLIENT_BONUS) $(PRINTF_SRC)$(PRINTF) $(LIBFT_SRC)$(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@make -C $(LIBFT_SRC) clean
	@make -C $(PRINTF_SRC) clean
	$(RM) $(SRS_DIR)/*.o

fclean:		clean
	@make -C $(LIBFT_SRC) fclean
	@make -C $(PRINTF_SRC) fclean
	$(RM) $(CLIENT) $(SERVER) $(SERVER_BONUS) $(CLIENT_BONUS)

re:			fclean all

.PHONY:		all clean fclean re bonus
