# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izail <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 17:36:05 by izail             #+#    #+#              #
#    Updated: 2022/03/29 17:36:06 by izail            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS = so_long_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX =  -lmlx -framework OpenGL -framework AppKit

SRC_M = mandatory/so_long.c mandatory/ft_read_map.c mandatory/fill_map.c\
		mandatory/checks.c  mandatory/checks_2.c mandatory/ft_draw.c mandatory/move_player.c  mandatory/moves.c\

SRC_B = bonus/so_long.c bonus/ft_read_map.c bonus/fill_map.c\
		bonus/checks.c bonus/checks_2.c bonus/ft_draw.c bonus/move_player.c  bonus/moves.c bonus/ft_animation.c\
	
SRC_GNL = includes/gnl/get_next_line.c\

SRC_PRINTF	= includes/ft_printf/ft_hex.c\
	includes/ft_printf/ft_nbr_str.c\
	includes/ft_printf/ft_printf.c\

HEADERS = mandatory/so_long.h\
	includes/ft_printf/ft_printf.h\
	includes/gnl/get_next_line.h\

OBJ_M	= $(SRC_M:.c=.o)
OBJ_B	= $(SRC_B:.c=.o)

OBJ_GNL	= $(SRC_GNL:.c=.o)

OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_M) $(OBJ_GNL) $(OBJ_PRINTF) $(HEADERS)
	$(CC) $(FLAGS) $(MLX) $(OBJ_M) $(OBJ_GNL) $(OBJ_PRINTF) -o $(NAME)

bonus : $(BONUS)

$(BONUS): $(OBJ_B) $(OBJ_GNL) $(OBJ_PRINTF) 
	$(CC) $(FLAGS) $(MLX) $(OBJ_B) $(OBJ_GNL) $(OBJ_PRINTF) -o $(BONUS)

clean:
	@rm -rf $(OBJ_M) $(OBJ_GNL) $(OBJ_PRINTF)
	@rm -rf $(OBJ_B) $(OBJ_GNL) $(OBJ_PRINTF)
fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS)

re: fclean all

.PHONY : re clean fclean all bonus