# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:18:53 by escura            #+#    #+#              #
#    Updated: 2023/12/13 17:57:14 by escura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------------------- Settings -----------------------------

NAME = minitalk
SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Werror -Wextra

# ------------------------------ Sources ------------------------------

SERVER_DIR = ./src/server
CLIENT_DIR = ./src/client
INCLUDES_DIR = ./includes
OBJ_DIR = ./obj

PRINTF_DIR = ./$(INCLUDES_DIR)/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./$(INCLUDES_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

SERVER_FILES = server.c utils_server.c
CLIENT_FILES = client.c utils_client.c

IFLAGS = -I$(INCLUDES_DIR)/libft -I$(INCLUDES_DIR)/ft_printf
LFLAGS = -L$(INCLUDES_DIR)/libft -L$(INCLUDES_DIR)/ft_printf -lftprintf -lft

SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(SERVER_FILES:.c=.o))
CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(CLIENT_FILES:.c=.o))

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

SERV_READY	=	echo "\n📥 Server ready!\n"

CLI_READY	=	echo "\n📟 Client ready!\n"

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# ------------------------------ Rules ------------------------------

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(PRINTF) $(OBJ_DIR) $(SERVER) $(CLIENT)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) -o $(SERVER) $(LFLAGS)
	@$(SERV_READY)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) -o $(CLIENT) $(LFLAGS) 
	@$(CLI_READY)

$(OBJ_DIR)/%.o: $(SERVER_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(CLIENT_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	rm -rf $(OBJ_DIR)
	@$(CLEANED)
	
fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)
	@$(FCLEANED)

re: fclean all

.PHONY: all minitalk bonus clean fclean re