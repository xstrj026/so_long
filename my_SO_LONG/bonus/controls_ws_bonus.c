/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_ws.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:24:12 by jucalder          #+#    #+#             */
/*   Updated: 2023/12/10 20:57:21 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

static int	keyboard_w(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	j--;
	if (game->map[j][i] == '1')
		return (0);
	k = right_move(game, i, j);
	if (!k)
		return (0);
	game->map[j + 1][i] = '0';
	ft_printf("Steps Count: %i\n", game->counter);
	ft_printf("Remaining Treasure: %i\n", game->collectables);
	return (1);
}

static int	keyboard_s(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	j++;
	if (game->map[j][i] == '1')
		return (0);
	k = right_move(game, i, j);
	if (!k)
		return (0);
	game->map[j - 1][i] = '0';
	ft_printf("Steps Count: %i\n", game->counter);
	ft_printf("Remaining Treasure: %i\n", game->collectables);
	return (1);
}

int	controls_ws_working(int command, t_complete *game)
{
	int	works;

	works = 0;
	if (command == XK_Up || command == 119)
		works = keyboard_w(game);
	if (command == XK_Down || command == 115)
		works = keyboard_s(game);
	return (works);
}
