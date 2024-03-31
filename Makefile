# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    $(MAKE)file                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 11:54:33 by acherraq          #+#    #+#              #
#    Updated: 2024/03/30 15:55:29 by acherraq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

SOURCES_BONUS = server_bonus.c client_bonus.c
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror


all: server client

bonus: server_bonus client_bonus


server: server.o minitalk.h printf/libftprintf.a libft/libft.a
	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft -Lprintf -lftprintf

client: client.o minitalk.h printf/libftprintf.a libft/libft.a
	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft -Lprintf -lftprintf

server_bonus: server_bonus.o minitalk_bonus.h printf/libftprintf.a libft/libft.a
	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft -Lprintf -lftprintf

client_bonus: client_bonus.o minitalk_bonus.h printf/libftprintf.a libft/libft.a
	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft -Lprintf -lftprintf
	
%.o: %.c | libft printf
	$(CC) -c $(CFLAGS) $<

libft:
	make -C libft

printf:
	make -C printf

clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)
	make -C libft clean
	make -C printf clean
	
fclean: clean
	rm -f server client 
	rm -f server_bonus client_bonus
	make -C libft fclean
	make -C printf fclean
	
re: fclean all

.PHONY: all bonus libft printf clean fclean re