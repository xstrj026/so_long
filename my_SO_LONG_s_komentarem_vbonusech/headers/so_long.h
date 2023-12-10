/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:56:44 by jucalder          #+#    #+#             */
/*   Updated: 2023/12/10 21:49:15 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "../minilibx/mlx.h"
# include "../headers/ft_printf.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct t_start
{
	unsigned long	last_update_time;
	int				fd;
	int				heightmap;
	int				widthmap;
	int				playercount;
	int				columncount;
	int				exitcount;
	int				x_axis;
	int				y_axis;
	int				counter;
	int				collectables;
	int				fe_width;
	int				fe_height;
	int				fp_width;
	int				fp_height;
	int				en_width;
	int				en_height;
	int				animation_counter;

	char			**map;
	char			**mapcpy;
	char			**tmpr;
	char			*string;
	char			*en_pic;

	void			*floor;
	void			*barrier;
	void			*player;
	void			*exit;
	void			*collectable;
	void			*enemy0;
	void			*enemy1;
	void			*enemy2;
	void			*enemy3;
	void			*enemy4;

	void			*mlxpointer;
	void			*winpointer;
}	t_complete;

int		exit_point(t_complete *game);
int		map_reading(t_complete *game, char *filename);
int		controls_working(int command, t_complete *game);
int		controls_ad_working(int command, t_complete *game);
int		controls_ws_working(int command, t_complete *game);
void	ft_error(t_complete *game, char *error);
void	adding_in_graphics(t_complete *game);
void	process_graphics(t_complete *game, int height, int width);
void	place_images_in_game(t_complete *game);
void	check_errors(t_complete *game);
void	character_valid(t_complete *game);
void	count_checker(t_complete *game, int height, int width);
void	if_walls(t_complete *game);
void	*ft_memset(void *b, int c, size_t length);
void	ft_valid_path(t_complete *id);
int		verticalwall(t_complete *game);
int		horizontalwall(t_complete *game);
char	*ft_strdup(const char *s);
void	ft_mapcpy(t_complete *id);
void	*ft_calloc(size_t nmemb, size_t size);
void	find_p_in_cpy(t_complete *id);
void	find_e_in_cpy(t_complete *id);
char	*ft_itoa(int n);
void	place_enemys(t_complete *game, int height, int width);
int		right_move(t_complete *game, int i, int j);

#endif
