# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 10:50:48 by poverbec          #+#    #+#              #
#    Updated: 2025/02/25 15:25:35 by poverbec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# MLX 		=	$(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast -ffast-math -march=native -mtune=native -funroll-loops


# CFLAGS			= -Wall -Werror -Wextra -Wunreachable-code -Ofast -ffast-math -march=native -mtune=native -funroll-loops #-lm
# all: mlx ${NAME}

# ${NAME}: $(OBJECTS)
# 	${CC} ${CFLAGS} -o ${NAME} $(OBJECTS) $(LIBFT) $(MLX)


NAME 	= so_long
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
LIBFT	= ./libft/libft.a
MLX_DIR = ./mlx
MLX_NAME =	$(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast -ffast-math -march=native -mtune=native -funroll-loops

SOURCE_DIR = src/
OBJ_DIR = obj/
BIN_DIR = bin/


# ---------- Subjects ---------- #
MY_SOURCES = \
			$(SOURCE_DIR)main.c \
			$(SOURCE_DIR)helper.c 
			
			
# ---------- Objects ---------- #

MY_OBJECTS=$(MY_SOURCES:$(SOURCE_DIR)%.c=$(OBJ_DIR)%.o)


# ---------- COLORS AND STUFF ---------- #
Color_Off = \033[0m
BIYellow = \033[1;93m
Yellow = \033[0;33m
BGreen = \033[1;32m 
On_Yellow = \033[43m
On_Green = \033[42m
Red = \033[0;31m

all: $(NAME)

$(OBJ_DIR)%.o: $(SOURCE_DIR)%.c | $(OBJ_DIR)
	$(CC)	$(CFLAGS)	-c $<	-o $@

$(OBJ_DIR):
	mkdir -p	$(OBJ_DIR)
	
$(NAME): checkMLX $(MY_OBJECTS) $(LIBFT)
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

checkMLX:
	@if	[ ! -d "$(MLX_DIR)" ];	then	\
        echo "$(YELLOW)Downloading MLX42...$(NC)"; \
        git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR) && \
        cmake -B $(MLX_DIR)/build -S $(MLX_DIR) && \
        make -C $(MLX_DIR)/build; \
        if [ $$? -ne 0 ]; then \
            echo "$(RED)Error building MLX42$(NC)"; \
            exit 1; \
        fi; \
        echo "$(GREEN)MLX42 installed$(NC)"; \
    else \
        echo "$(GREEN)MLX42 already exists$(NC)"; \
    fi
			



clean:
	@echo "$(Yellow)-----Removing Object Files--------$(Color_Off)"
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	make -C libft fclean
	@rm -rf $(LIBMLX)/build

fclean: clean
	@echo "$(On_Yellow)Removing Executables...$(Color_Off)"
	@rm -f $(NAME)
	make -C libft fclean

re: fclean all

f: fclean
f: CFLAGS += -g -fsanitize=address
f: $(NAME)

.PHONY: re clean fclean all
