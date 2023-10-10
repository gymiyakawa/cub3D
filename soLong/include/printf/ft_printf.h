/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:10:46 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/09/11 15:53:47 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	printchar(char c, int *len);
void	printstring(char *str, int *len);
void	printpointer(unsigned long int ptr, int *len);
void	printnumber(int nb, int *len);
void	printhexaandu(unsigned int hx, char conversion, int *len);

#endif
