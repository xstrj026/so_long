/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:02:21 by jstrojsa          #+#    #+#             */
/*   Updated: 2023/12/08 16:02:21 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Načte obrázky pro herní objekty pomocí funkce mlx_xpm_file_to_image a 
uloží je do odpovídajících atributů struktury game. */
void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/0.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/1.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/P.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/E.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/C.xpm", &i, &j);
	game->enemy0 = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/U0.xpm", &i, &j);
	game->enemy1 = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/U1.xpm", &i, &j);
	game->enemy2 = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/U2.xpm", &i, &j);
	game->enemy3 = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/U3.xpm", &i, &j);
	game->enemy4 = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/U4.xpm", &i, &j);
	game->en_pic = game->enemy0;
}

/* Umístí obrázek hráče do okna na pozici určené zadanými souřadnicemi 
(height, width) na základě velikosti dlaždice 40x40 pixelů.
Aktualizuje pozici hráče (game->y_axis a game->x_axis). */
void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

/* Umístí obrázek sběratelného objektu do okna na pozici určené zadanými 
souřadnicemi (height, width).
Inkrementuje počet sběratelných objektů (game->collectables). */
void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->collectable, width * 40, height * 40);
	game->collectables++;
}

/* Prochází mapu a podle obsahu jednotlivých polí určuje, který herní
 objekt má být umístěn na danou pozici v okně.
Volá odpovídající funkce pro umístění překážky, sběratelného objektu,
 hráče, východu nebo podlahy. */
void	process_graphics(t_complete *game, int height, int width)
{
	if (game->map[height][width] == '1')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->barrier, width * 40, height * 40);
	if (game->map[height][width] == 'C')
		place_collectable(game, height, width);
	if (game->map[height][width] == 'P')
		place_player(game, height, width);
	if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->exit, width * 40, height * 40);
	if (game->map[height][width] == '0')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->floor, width * 40, height * 40);
	if (game->map[height][width] == 'U')
		place_enemys(game, height, width);
}

/* Prochází celou mapu a volá funkci process_graphics pro každou pozici
 v mapě, což umožňuje umístit všechny herní objekty do okna grafického
  uživatelského rozhraní. */
void	adding_in_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			process_graphics(game, height, width);
			width++;
		}
		height++;
	}
}
