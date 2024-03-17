# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 11:54:33 by acherraq          #+#    #+#              #
#    Updated: 2024/03/17 14:58:49 by acherraq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME = libminitalk.a
CFLAGS = -Wall -Werror -Wextra
PRINTF = ./printf/libftprintf.a
LIBFT = ./libft/libft.a
CC = cc
RM = rm -f
# AR = ar -rcs

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_SRC_BONUS = server_bonus.c
CLIENT_SRC_BONUS = client_bonus.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_OBJ_BONUS = $(SERVER_SRC_BONUS:.c=.o)
CLIENT_OBJ_BONUS = $(CLIENT_SRC_BONUS:.c=.o)
# $(NAME) : $(OBJS)
# 		$(AR) $(NAME) $(OBJS)
# %.o: %.c minitalk.h
# 	$(CC) $(CFLAGS) -c $< -o $@
all:  $(CLIENT) $(SERVER)
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT):
	$(MAKE) -C ./libft

$(PRINTF):
	$(MAKE) -C ./printf

$(CLIENT): $(CLIENT_OBJ) minitalk.h $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) $(PRINTF) -o client
	
$(SERVER): $(SERVER_OBJ) minitalk.h $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(PRINTF) $(LIBFT) -o server

$(CLIENT_BONUS): $(CLIENT_OBJ_BONUS) minitalk.h $(LIBFT) $(PRINTF)
				$(CC) $(CFLAGS) $(CLIENT_OBJ_BONUS) $(LIBFT) $(PRINTF) -o client_bonus
	
$(SERVER_BONUS): $(SERVER_OBJ_BONUS) minitalk.h $(LIBFT) $(PRINTF)
				$(CC) $(CFLAGS) $(SERVER_OBJ_BONUS) $(PRINTF) $(LIBFT) -o server_bonus
			
# $(CLIENT): $(CLIENT).c minitalk.h
# 		$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT).c
# $(NAME) : $(SERVER) $(CLIENT)	
clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_OBJ_BONUS) $(CLIENT_OBJ_BONUS)
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./printf
fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS) 
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./printf



re:	fclean all bonus
.PHONY: all clean fclean re bonus