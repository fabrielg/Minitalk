# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 13:35:40 by gfrancoi          #+#    #+#              #
#    Updated: 2025/02/24 15:22:49 by gfrancoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME =		server
CLIENT_NAME =		client
CFLAGS =			-Wall -Wextra -Werror
LIBFT =				./libft/libft.a

SERVER_SRCS = \
	server.c

CLIENT_SRCS = \
	client.c

SERVER_OBJ_DIR = server_obj
CLIENT_OBJ_DIR = client_obj

SERVER_OBJS = $(addprefix $(SERVER_OBJ_DIR)/, $(notdir $(SERVER_SRCS:.c=.o)))
CLIENT_OBJS = $(addprefix $(CLIENT_OBJ_DIR)/, $(notdir $(CLIENT_SRCS:.c=.o)))

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(LIBFT) $(SERVER_OBJS)
	cc -g3 $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS) $(LIBFT)

$(CLIENT_NAME): $(LIBFT) $(CLIENT_OBJS)
	cc -g3 $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS) $(LIBFT)
	
$(LIBFT):
	make -C ./libft/

$(SERVER_OBJ_DIR)/%.o: %.c
	mkdir -p $(SERVER_OBJ_DIR)
	cc -g3 $(CFLAGS) -c -o $@ $^

$(CLIENT_OBJ_DIR)/%.o: %.c
	mkdir -p $(CLIENT_OBJ_DIR)
	cc -g3 $(CFLAGS) -c -o $@ $^

clean:
	make clean -C ./libft/
	rm -fr $(SERVER_OBJ_DIR) $(CLIENT_OBJ_DIR)

fclean: clean
	make fclean -C ./libft/
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all fclean clean re