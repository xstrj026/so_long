/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnmb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:52:40 by jstrojsa          #+#    #+#             */
/*   Updated: 2023/09/04 08:52:40 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_putchar('0');
	else
	{
		if (n / 10 != 0)
			ft_print_unsigned(n / 10);
		ft_putchar((n % 10) + '0');
		while (n > 0)
		{
			n /= 10;
			size++;
		}
	}
	return (size);
}

int	ft_printnmb(int nmb)
{
	int	size;

	size = 0;
	if (nmb == 0)
		size += ft_putchar('0');
	if (nmb == -2147483648)
	{
		size += ft_putstr("-2147483648");
		return (size);
	}
	if (nmb < 0)
	{
		size += ft_putchar('-');
		nmb = -nmb;
	}
	if (nmb > 0)
		size += ft_print_unsigned((unsigned int)nmb);
	return (size);
}
