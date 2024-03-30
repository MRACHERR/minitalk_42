# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 11:54:33 by acherraq          #+#    #+#              #
#    Updated: 2024/03/30 14:39:02 by acherraq         ###   ########.fr        #
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

server: server.o minitalk.h | libft printf
	$(CC) -o $@ $< -Llibft -lft -Lprintf -lftprintf

client: client.o minitalk.h | libft printf
	$(CC) -o $@ $< -Llibft -lft -Lprintf -lftprintf

server_bonus: server_bonus.o minitalk.h | libft printf
	$(CC) -o $@ $< -Llibft -lft -Lprintf -lftprintf

client_bonus: client_bonus.o minitalk.h | libft printf
	$(CC) -o $@ $< -Llibft -lft -Lprintf -lftprintf
	
%.o: %.c
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
	rm -f server client libft/libft.a printf/libftprintf.a
	rm -f server_bonus client_bonus

re: fclean all

.PHONY: all bonus libft printf clean fclean re