/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_ad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:19:50 by jucalder          #+#    #+#             */
/*   Updated: 2023/12/10 21:21:12 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

int	right_move(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		ft_printf("\nYou've colected all treasures and escaped!\nYou win!\n");
		exit_point(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

static int	keyboard_a(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	i--;
	if (game->map[j][i] == '1')
		return (0);
	k = right_move(game, i, j);
	if (!k)
		return (0);
	game->map[j][i + 1] = '0';
	ft_printf("Steps Count: %i\n", game->counter);
	ft_printf("Remaining Treasure: %i\n", game->collectables);
	return (1);
}

static int	keyboard_d(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	i++;
	if (game->map[j][i] == '1')
		return (0);
	k = right_move(game, i, j);
	if (!k)
		return (0);
	game->map[j][i - 1] = '0';
	ft_printf("Steps Count: %i\n", game->counter);
	ft_printf("Remaining Treasure: %i\n", game->collectables);
	return (1);
}

int	controls_ad_working(int command, t_complete *game)
{
	int	works;

	works = 0;
	if (command == XK_a || command == XK_Left)
		works = keyboard_a(game);
	else if (command == XK_d || command == XK_Right)
		works = keyboard_d(game);
	return (works);
}
	//XK_d == 100 == v hexademalni je to 100
