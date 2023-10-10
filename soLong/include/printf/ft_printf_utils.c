/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:42:40 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/09/11 19:16:47 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printchar(char c, int *len)
{
	*len += write(1, &c, 1);
}

void	printstring(char *str, int *len)
{
	if (!str)
		*len += write(1, "(null)", 6);
	else
		while (*str)
			*len += write(1, str++, 1);
}

void	printpointer(unsigned long int ptr, int *len)
{
	if (ptr >= 16)
		printpointer(ptr / 16, len);
	*len += write(1, &"0123456789abcdef"[ptr % 16], 1);
}

void	printnumber(int nb, int *len)
{
	if (nb == -2147483648)
	{
		*len += write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		*len += write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		printnumber(nb / 10, len);
	*len += write(1, &"0123456789"[nb % 10], 1);
}

void	printhexaandu(unsigned int nb, char conversion, int *len)
{
	unsigned int	base;

	base = 16;
	if (conversion == 'u')
		base = 10;
	if (nb >= base)
		printhexaandu(nb / base, conversion, len);
	if (conversion == 'x')
		*len += write(1, &"0123456789abcdef"[nb % 16], 1);
	else if (conversion == 'X')
		*len += write(1, &"0123456789ABCDEF"[nb % 16], 1);
	else
		*len += write(1, &"0123456789"[nb % base], 1);
}
