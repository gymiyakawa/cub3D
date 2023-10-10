/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:14:05 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/09/11 18:50:55 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_printer(char conversion, va_list ap, int *len)
{
	if (conversion == 'c')
		printchar(va_arg(ap, int), len);
	else if (conversion == 's')
		printstring(va_arg(ap, char *), len);
	else if (conversion == 'p')
	{
		*len += write(1, "0x", 2);
		printpointer(va_arg(ap, unsigned long), len);
	}
	else if (conversion == 'd' || conversion == 'i')
		printnumber(va_arg(ap, int), len);
	else if (conversion == 'x' || conversion == 'X' || conversion == 'u')
		printhexaandu(va_arg(ap, unsigned int), conversion, len);
	else if (conversion == '%')
		*len += write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
			format_printer(format[++i], ap, &len);
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
