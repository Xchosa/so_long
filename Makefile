# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 10:50:48 by poverbec          #+#    #+#              #
#    Updated: 2025/03/17 12:53:12 by poverbec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 	= so_long
CC		= cc
#CFLAGS	= -Wall -Wextra -Werror -g -I inc/ -ldl -lglfw -pthread -lm
#CFLAGS  = -Wall -Wextra -Werror -g -I inc/ -fsanitize=address
CFLAGS	= -Wall -Wextra -Werror -g -I inc/
LIBFT	= ./libft/libft.a
MLX_DIR = ./mlx


# ---------- McOS compiling ---------- #
MLX_NAME =	$(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
MLX 	=	$(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

# ---------- Linux compiling ---------- #

OBJ_DIR = obj
BIN_DIR = bin/
SOURCE_DIR = src/

# ---------- Subjects ---------- #
MY_SOURCES = \
			fill_map.c \
			main.c \
			images_to_struct.c \
			validate_map.c \
			valid_map_string.c \
			validate_path.c \
			validate_error.c \
			move_player.c \
			bonus.c \
			helper.c 
			
vpath %.c $(SOURCE_DIR)	

# ---------- Objects ---------- #

MY_OBJECTS := $(addprefix $(OBJ_DIR)/, $(MY_SOURCES:.c=.o))


# ---------- COLORS AND STUFF ---------- #
Color_Off = \033[0m
BIYellow = \033[1;93m
Yellow = \033[0;33m
BGreen = \033[1;32m 
On_Yellow = \033[43m
On_Green = \033[42m
Red = \033[0;31m

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	echo test
	
$(NAME): checkMLX $(LIBFT) $(MY_OBJECTS)
	@echo "$(BIYellow) Compiling $(NAME) $(Color_Off)"
	@$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIBFT) -o $(NAME) $(MLX)
	@if [ -f $(NAME) ]; then \
		echo "$(On_Yellow)------------------------------------------$(Color_Off)"; \
		echo "$(BGreen)PROCESS COMPLETED SUCCESSFULLY!$(Color_Off)"; \
		echo "$(On_Green)------------------------------------------$(Color_Off)"; \
	else \
		echo "$(Red)failed to compile $(NAME) $(Color_Off)"; \
		exit 1; \
	fi

$(LIBFT):
	make -C ./libft

test: CFLAGS = -g
test: $(NAME)

checkMLX:
	@if	[ ! -d "$(MLX_DIR)" ];	then	\
        echo "$(Yellow)Downloading MLX42...$(Color_Off)"; \
        git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR) && \
		cmake -B $(MLX_DIR)/build -S $(MLX_DIR) && \
        make -C $(MLX_DIR)/build; \
        if [ $$? -ne 0 ]; then \
            echo "$(Red)Error building MLX42$(Color_Off)"; \
            exit 1; \
        fi; \
        echo "$(BGreen)MLX42 installed$(Color_Off)"; \
    else \
        echo "$(BGreen)MLX42 already exists$(Color_Off)"; \
    fi
			

clean:
	@echo "$(Yellow)-----Removing Object Files--------$(Color_Off)"
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	make -C libft fclean
	@rm -rf $(MLX_DIR)/build

fclean: clean
	@echo "$(On_Yellow)Removing Executables...$(Color_Off)"
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	make -C libft fclean
	@rm -rf $(MLX_DIR)

re: 
	$(MAKE) fclean
	$(MAKE) all

# f: fclean
# f: CFLAGS += -g -fsanitize=address
f: fclean	# $(CFLAGS) += -g -fsanitize=address

.PHONY: re clean fclean all checkMLX test
