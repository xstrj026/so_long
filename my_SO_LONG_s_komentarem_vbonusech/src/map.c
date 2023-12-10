/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:33:02 by jstrojsa          #+#    #+#             */
/*   Updated: 2023/12/07 19:33:02 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Tato funkce zjišťuje šířku mapy na základě jednoho řádku. Počítá, 
kolik znaků je v řetězci, bez zapocitani \n */
static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] && string[width] != '\n')
		width++;
	return (width);
}

/* add_line: Tato funkce přidává nový řádek do mapy. Zvyšuje výšku mapy o jedna,
 alokuje nový blok paměti pro mapu (s novým řádkem) a kopíruje staré řádky do 
 nové mapy. */
static int	add_line(t_complete *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temp = (char **)malloc(sizeof(char *) * (game->heightmap +1));
	temp[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free (game->map);
	game->map = temp;
	return (1);
}

/* map_reading: Tato funkce načítá mapu ze souboru pomocí funkce get_next_line 
. Funkce get_next_line vrací řádek textu ze souboru.
Pokud bylo úspěšné načtení řádku, je volána funkce add_line, 
která přidá nový řádek do mapy.
Pokud dojde k chybě nebo není další řádek, cyklus se přeruší.
Po načtení všech řádků ze souboru se uzavře soubor a určí se šířka mapy 
na základě prvního řádku. */
int	map_reading(t_complete *game, char *filename)
{
	char	*readmap;

	game->fd = open(filename, O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close (game->fd);
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}
//do tohoto ukl8d8m vysku mapy
/* do fd; open otevre soubor a vraci fd */
//zaznamenava vysku mapy do game.heighmap
