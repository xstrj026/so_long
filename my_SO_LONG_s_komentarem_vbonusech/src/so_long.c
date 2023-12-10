/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:45:45 by jstrojsa          #+#    #+#             */
/*   Updated: 2023/12/07 14:45:45 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	change_count(t_complete *game)
{
	char	*number;

	number = ft_itoa(game->counter);
	mlx_string_put(game->mlxpointer, game->winpointer, 10, 40, 0xFFFFFF,
		number);
	mlx_string_put(game->mlxpointer, game->winpointer, 10, 20, 0xFFFFFF,
		"Count of steps");
	free(number);
	return (0);
}

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
	{
		ft_printf("Error\nSecond parameter needed (./so_long ./map.ber)\n");
		return (0);
	}
	ft_memset(&game, 0, sizeof(t_complete));
	map_reading(&game, argv[1]);
	check_errors(&game);
	game.mlxpointer = mlx_init();
	if (!game.mlxpointer)
		ft_error(&game, "Error\nwrong mlx_init(), game.mlxpointer==NULL\n");
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 40),
			(game.heightmap * 40), "so_long");
	if (!game.winpointer)
		ft_error(&game, "Error\nwrong window init, game.winpointer==NULL\n");
	place_images_in_game(&game);
	adding_in_graphics(&game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 17, 0, exit_point, &game);
	mlx_loop_hook(game.mlxpointer, change_count, &game);
	mlx_loop(game.mlxpointer);
}
/* nastaveni pameti, inicializace struktury a nastaveni hodnot clenu na 0*/
/* cteni mapy, ukladani dat do structu, zjisteni velikosti mapy */
/* nyni je treba zjisti chyby v mape */
/* vztvoreni okna */
/* key hook nastavuje reakci, ktera se ma provest po uvolneni stisknute 
klavesy */
/* vytvoreni smycky */