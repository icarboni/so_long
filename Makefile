# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 19:53:24 by icarboni          #+#    #+#              #
#    Updated: 2023/05/28 18:25:20 by icarboni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft.a
PRINTF = libftprintf.a
CC = clang
FLAG = -Wall -Wextra -Werror
SRC = src/so_long.c src/map.c src/map_checks.c src/images.c src/keys.c src/flood_fill.c src/exit.c $(GNL)
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ = ${SRC:.c=.o}
LIBFT_PATH = ./libft
PRINTF_PATH = ./libft/ft_printf
MLX = ./mlx/libmlx.a

all: make_libft $(NAME)

make_libft:
	cd $(LIBFT_PATH) && $(MAKE) 

%.o: %.c
	$(CC) $(FLAG) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAG) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT_PATH)/$(LIBFT) $(PRINTF_PATH)/$(PRINTF) $(MLX)

clean:
	/bin/rm -f $(OBJ)
	cd $(LIBFT_PATH) && $(MAKE) clean
	cd $(PRINTF_PATH) && $(MAKE) clean

fclean: clean
	/bin/rm -f $(NAME)
	cd $(LIBFT_PATH) && /bin/rm -f $(LIBFT)
	cd $(PRINTF_PATH) && /bin/rm -f $(PRINTF)

re: fclean all

.PHONY: clean fclean all re
