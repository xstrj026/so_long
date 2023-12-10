/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:15:28 by jstrojsa          #+#    #+#             */
/*   Updated: 2023/12/08 16:15:28 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freemap(t_complete *id)
{
	int	i;

	i = 0;
	if (id->map)
	{
		while (id->map[i])
		{
			free(id->map[i]);
			i++;
		}
		free(id->map);
	}
	i = 0;
	if (id->mapcpy)
	{
		while (id->mapcpy[i])
		{
			free(id->mapcpy[i]);
			i++;
		}
		free(id->mapcpy);
	}
}

void	ft_destroy(t_complete *id)
{
	mlx_destroy_image(id->mlxpointer, id->floor);
	mlx_destroy_image(id->mlxpointer, id->player);
	mlx_destroy_image(id->mlxpointer, id->barrier);
	mlx_destroy_image(id->mlxpointer, id->exit);
	mlx_destroy_image(id->mlxpointer, id->collectable);
	mlx_destroy_image(id->mlxpointer, id->enemy0);
	mlx_destroy_image(id->mlxpointer, id->enemy1);
	mlx_destroy_image(id->mlxpointer, id->enemy2);
	mlx_destroy_image(id->mlxpointer, id->enemy3);
	mlx_destroy_image(id->mlxpointer, id->enemy4);
	mlx_destroy_window(id->mlxpointer, id->winpointer);
	mlx_destroy_display(id->mlxpointer);
}

//funkce uvolni pamet ve stuct a ukonci program
int	exit_point(t_complete *game)
{
	ft_printf("\nClosing program and cleaning memmory\n");
	ft_freemap(game);
	if (game->winpointer)
		ft_destroy(game);
	free(game->mlxpointer);
	exit(0);
}

/* funkce ukonci program a vzpise chbovou hlasku */
void	ft_error(t_complete *game, char *error)
{
	ft_printf(error);
	exit_point(game);
}
