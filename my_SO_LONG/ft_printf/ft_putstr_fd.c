/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:12:20 by jstrojsa          #+#    #+#             */
/*   Updated: 2023/09/04 13:33:42 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

//mozna bude potreba unsigned int
/*	lze i pouzit predchozi funkci; mozna bude potreba podminka if
if (!s)
	return ;
while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}*/