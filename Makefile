# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 18:24:36 by nsidqi            #+#    #+#              #
#    Updated: 2024/01/31 15:18:15 by nsidqi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT_NAME = client
SERVER_NAME = server
BONUS_CLIENT_NAME = client_bonus
BONUS_SERVER_NAME = server_bonus

SRC_CLIENT = client.c
SRC_SERVER = server.c
BONUS_SRC_CLIENT = client_bonus.c
BONUS_SRC_SERVER = server_bonus.c
SRC = utils.c utils_2.c

all : $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME) : $(SRC_CLIENT) lib.h $(SRC)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(SRC_CLIENT) $(SRC)

$(SERVER_NAME) : $(SRC_SERVER) lib.h $(SRC)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SRC_SERVER) $(SRC)

$(BONUS_CLIENT_NAME) : $(BONUS_SRC_CLIENT) lib.h $(SRC)
	$(CC) $(CFLAGS) -o $(BONUS_CLIENT_NAME) $(BONUS_SRC_CLIENT) $(SRC)

$(BONUS_SERVER_NAME) : $(BONUS_SRC_SERVER) lib.h $(SRC)
	$(CC) $(CFLAGS) -o $(BONUS_SERVER_NAME) $(BONUS_SRC_SERVER) $(SRC)
	
bonus : $(BONUS_CLIENT_NAME) $(BONUS_SERVER_NAME)

clean :
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

fclean : clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) $(BONUS_CLIENT_NAME) $(BONUS_SERVER_NAME)

re : fclean all

.PHONY : all fclean clean re bonus
