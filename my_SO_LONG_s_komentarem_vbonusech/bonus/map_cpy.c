/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:13:00 by jstrojsa          #+#    #+#             */
/*   Updated: 2023/12/08 20:13:00 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	ft_linecpy(t_complete *id, int y)
{
	int		i;

	i = 0;
	while (id->map[y][i])
		i++;
	id->mapcpy[y] = malloc(i + 1);
	if (!id->mapcpy[y])
		return (free(id->mapcpy), ft_error(id, "ERROR: mem alloc\n"));
	id->mapcpy[y] = ft_strcpy(id->mapcpy[y], id->map[y]);
	id->mapcpy[y][i] = '\0';
}

/*Memory allocation for copy of map*/
void	ft_mapcpy(t_complete *id)
{
	int		count;

	count = 0;
	while (id->map[count])
	{
		count++;
	}
	id->mapcpy = ft_calloc(count + 1, sizeof(char *));
	if (!id->mapcpy)
		return (free(id->mapcpy), ft_error(id, "ERROR: mem alloc\n"));
	count = 0;
	while (id->map[count])
	{
		ft_linecpy(id, count);
		count++;
	}
	id->mapcpy[count] = NULL;
}

//save player position into struct
void	find_p_in_cpy(t_complete *id)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y < id->heightmap)
	{	
		x = 0;
		while(x < id->widthmap)
		{
			if (id->mapcpy[y][x] == 'P')
			{
				ft_printf("\nsouradnice P jsou X:%d Y:%d \n", x, y);
				id->fp_width = x;
				id->fp_height = y;
			}
			x++;
		}
		y++;
	}
	printf("\nid->fp_width = %d \n", id->fp_width);
	printf("\nid->fp_height = %d \n", id->fp_height);
}

//save exit position into struct
void	find_e_in_cpy(t_complete *id)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y < id->heightmap)
	{	
		x = 0;
		while(x < id->widthmap)
		{
			if (id->mapcpy[y][x] == 'E')
			{
				ft_printf("\nsouradnice E jsou X:%d Y:%d \n", x, y);
				id->fe_width = x;
				id->fe_height = y;
			}
			x++;
		}
		y++;
	}
	printf("\nid->fe_width = %d \n", id->fe_width);
	printf("\nid->fe_height = %d \n", id->fe_height);
}