/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:53:05 by jstrojsa          #+#    #+#             */
/*   Updated: 2023/12/10 15:53:05 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_enemys(t_complete *game, int height, int width)
{
	if (game->en_height != height)
		game->en_height = height;
	if (game->en_width != width)
		game->en_width = width;
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->en_pic, width * 40, height * 40);
	game->animation_counter++;
	if (game->en_pic == game->enemy0)
		game->en_pic = game->enemy1;
	else if (game->en_pic == game->enemy1)
		game->en_pic = game->enemy2;
	else if (game->en_pic == game->enemy2)
		game->en_pic = game->enemy3;
	else if (game->en_pic == game->enemy3)
		game->en_pic = game->enemy4;
	else if (game->en_pic == game->enemy4)
		game->en_pic = game->enemy0;
}
