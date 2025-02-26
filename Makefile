# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 13:35:40 by gfrancoi          #+#    #+#              #
#    Updated: 2025/02/26 19:39:21 by gfrancoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME =		server
CLIENT_NAME =		client
CFLAGS =			-Wall -Wextra -Werror
LIBFT =				./libft/libft.a

SERVER_SRCS = \
	server.c\
	init_signal.c\
	command_manager.c

CLIENT_SRCS = \
	client.c\
	init_signal.c

COMMANDS_SRCS = \
	commands/command_exit.c\
	commands/command_linux.c\
	commands/command_heart.c\
	commands/command_quoi.c\
	commands/emoji_heart.c

SERVER_OBJ_DIR = server_obj
CLIENT_OBJ_DIR = client_obj

SERVER_OBJS =	$(addprefix $(SERVER_OBJ_DIR)/, $(notdir $(SERVER_SRCS:.c=.o))) \
				$(addprefix $(SERVER_OBJ_DIR)/, $(addsuffix .o, $(basename $(COMMANDS_SRCS))))
CLIENT_OBJS =	$(addprefix $(CLIENT_OBJ_DIR)/, $(notdir $(CLIENT_SRCS:.c=.o)))

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

$(SERVER_OBJ_DIR)/commands/%.o: commands/%.c
	mkdir -p $(SERVER_OBJ_DIR)/commands
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