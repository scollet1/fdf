# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scollet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/09 02:06:32 by scollet           #+#    #+#              #
#    Updated: 2017/06/09 02:06:34 by scollet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
PATH_SRC = ./
FT = ./libft/libft.h
MLX = ./minilibx_macos/mlx.h

SRC = draw.c \
			error.c \
			grid.c \
			key.c \
			main.c \
			tools.c

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

HEAD = fdf.h

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

#LIB = -L libft -lft -L minilibx_macos -lmlx
#CFLAGS += -Wall -Wextra -I libft -I minilibx_macos

all: $(NAME)
	@echo "\033[04;32mfdf Compilation completed!\033[0m"

$(NAME): $(OBJ)
	@make -C libft
	@make -C minilibx_macos
	@$(CC) $(CFLAGS) -I $(FT) -I $(MLX) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

.PHONY: clean fclean re
		#@make -C minilibx_macos
		#@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) #-framework OpenGL -framework AppKit
	#$(OBJ):
		#@gcc $(CFLAGS) -I includes -I libft/includes -c $*.c -o $@

clean:
	@make -C libft clean
	@make -C minilibx_macos clean
	@echo "Cleaning .o processing ..."
	@rm -rf $(OBJ)
	@echo "Cleaning .o completed !"

fclean: clean
	@make -C libft clean
	@make -C minilibx_macos clean
	@echo "Fclean processing ..."
	@rm -f $(NAME)
	@echo "Fclean completed !"

re: fclean all

#.PHONY: all clean fclean re

#NAME = fdf
#SRC =
#SRC_DIR = srcs/
#INCLUDES_DIR = includes/
#FILES = draw 	\
				error \
				fdf 	\
				main 	\
				tools \
				read  \

#BINS = $(patsubst %,%.o,$(FILES))
#FLAGS = -Wall -Werror -Wextra

#.PHONY: all clean fclean re

#all: $(NAME)

#$(BINS):
	#@gcc -I$(INCLUDES_DIR) $(FLAGS) -c $(patsubst %.o,$(SRC_DIR)%.c,$@)

#$(NAME): $(BINS)
	#@gcc -I$(INCLUDES_DIR) $(FLAGS) $(BINS) -o $(NAME)

#clean:
	#@/bin/rm -f $(BINS)

#fclean: clean
	#@/bin/rm -f $(NAME)

#re: fclean all
