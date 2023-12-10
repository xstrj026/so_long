/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:51:34 by jstrojsa          #+#    #+#             */
/*   Updated: 2023/02/24 23:51:34 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *string)
{
	size_t	len;

	len = 0;
	while (*string)
	{
		len++;
		string++;
	}
	return (len);
}
