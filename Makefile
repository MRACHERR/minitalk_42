# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 11:54:33 by acherraq          #+#    #+#              #
#    Updated: 2024/03/13 09:49:54 by acherraq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libminitalk.a
CFLAGS = -Wall -Werror -Wextra
PRINTF = ./printf/libftprintf.a
LIBFT = ./libft/libft.a
CC = cc
RM = rm -f
# AR = ar -rcs

SERVER = server
CLIENT = client

SERVER_SRC = server.c
CLIENT_SRC = client.c


SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
# $(NAME) : $(OBJS)
# 		$(AR) $(NAME) $(OBJS)
# %.o: %.c minitalk.h
# 	$(CC) $(CFLAGS) -c $< -o $@
all:  $(CLIENT) $(SERVER)

$(LIBFT):
	$(MAKE) -C ./libft

$(PRINTF):
	$(MAKE) -C ./printf

$(CLIENT): $(CLIENT_OBJ) minitalk.h $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) $(PRINTF) -o client
	
$(SERVER): $(SERVER_OBJ) minitalk.h $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(PRINTF) $(LIBFT) -o server 
			
# $(CLIENT): $(CLIENT).c minitalk.h
# 		$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT).c
# $(NAME) : $(SERVER) $(CLIENT)	
clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./printf
fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./printf
	

re:	fclean all
.PHONY: all clean fclean re