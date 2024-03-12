# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 11:54:33 by acherraq          #+#    #+#              #
#    Updated: 2024/03/09 13:39:09 by acherraq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libminitalk.a
CFLAGS = -Wall -Werror -Wextra
CC = cc
RM = rm -f
AR = ar -rcs

SRCS = client.c server.c
OBJS = $(SRCS:.c=.o)
$(NAME) : $(OBJS)
		$(AR) $(NAME) $(OBJS)
%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@
all: $(NAME)

# $(SERVER): $(SERVER).c minitalk.h
# 		@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER).c
			
# $(CLIENT): $(CLIENT).c minitalk.h
# 		$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT).c
# $(NAME) : $(SERVER) $(CLIENT)	
clean: 
	$(RM) $(OBJS)
fclean: 
	$(RM) $(NAME)
re:	fclean all
.PHONY: all clean fclean re