/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:59:00 by jstrojsa          #+#    #+#             */
/*   Updated: 2023/12/08 15:59:00 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*If next tile is 1(wall) = recurse die*/
int	ft_path_control(t_complete *id, int x, int y)
{
	if (id->mapcpy[y][x] == '1' || id->mapcpy[y][x] == 'E')
		return (0);
	if (id->mapcpy[y][x] == 'U')
	{
		return (0);
	}
	return (1);
}
//printf("\nkontroluji souradnice X:%d Y:%d \n", x, y);

/*Floof fill check*/
void	ft_flood_fill(t_complete *id, int x, int y)
{
	while (id->mapcpy[y][x] != '#')
	{
		id->mapcpy[y][x] = '#';
		if (ft_path_control(id, x + 1, y))
			ft_flood_fill(id, x + 1, y);
		if (ft_path_control(id, x - 1, y))
			ft_flood_fill(id, x - 1, y);
		if (ft_path_control(id, x, y + 1))
			ft_flood_fill(id, x, y + 1);
		if (ft_path_control(id, x, y - 1))
			ft_flood_fill(id, x, y - 1);
	}
}

void	path_check(t_complete *id, int y, int x, char c)
{
	if (id->mapcpy[y][x + 1] == c)
		return ;
	if (id->mapcpy[y][x - 1] == c)
		return ;
	if (id->mapcpy[y + 1][x] == c)
		return ;
	if (id->mapcpy[y - 1][x] == c)
		return ;
	ft_printf("Error\nThe game is unwinable. Enemy block all the path.\n\n");
	ft_error(id, "\nOr the path to exit is not valid.\n");
}

void	find_c_in_cpy(t_complete *id)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < id->heightmap)
	{	
		x = 0;
		while (x < id->widthmap)
		{
			if (id->mapcpy[y][x] == 'C')
				ft_error(id, "No valid path to all collectibles in map");
			x++;
		}
		y++;
	}
}

/* the function will find valid path, or return error messege and exit */
void	ft_valid_path(t_complete *id)
{
	ft_mapcpy(id);
	find_p_in_cpy(id);
	find_e_in_cpy(id);
	ft_flood_fill(id, id->fp_width, id->fp_height);
	path_check(id, id->fe_height, id->fe_width, '#');
	find_c_in_cpy(id);
}
