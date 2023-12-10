/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:42:10 by jucalder          #+#    #+#             */
/*   Updated: 2023/12/10 11:58:36 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

//function 
int	controls_working(int command, t_complete *game)
{
	int	works;

	works = 0;
	if (command == XK_Escape)
		exit_point(game);
	else
	{
		works = controls_ws_working(command, game);
		if (!works)
			works = controls_ad_working(command, game);
	}
	if (works)
		adding_in_graphics(game);
	return (1);
}
//KEYSYM is more portable than keycode(dependent on hardware)
//