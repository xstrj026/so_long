# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 22:36:40 by jstrojsa          #+#    #+#              #
#    Updated: 2023/12/10 23:00:53 by jstrojsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
NAME_BONUS := so_long_bonus

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := src/*.c
BONUS_SRC := bonus/*.c
GETNEXTLINE := get_next_line/*c
LIBRARY := -lmlx -lXext -lX11 -L./minilibx
PRINTF_LIB := ft_printf/libftprintf.a
PRINTF := ft_printf/*c 
MINILIBX := minilibx/

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

all:
	make -C $(MINILIBX)
	make -C ft_printf
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(PRINTF_LIB) $(LIBRARY) -o $(NAME)

bonus:
	make -C $(MINILIBX)
	make -C ft_printf
	$(CC) $(CFLAGS) $(BONUS_SRC) $(GETNEXTLINE) $(PRINTF_LIB) $(LIBRARY) -o $(NAME_BONUS)

clean:
	make fclean -C ft_printf
	make clean -C $(MINILIBX)

fclean:
	make clean -C $(MINILIBX)
	make fclean -C ft_printf
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all

run_bonus:
	make bonus
	valgrind ./so_long_bonus ./maps/level1.ber

run:
	make all
	valgrind ./so_long ./maps/level1.ber

.PHONY: all bonus clean fclean run run_bonus re