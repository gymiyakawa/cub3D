/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:17:38 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/10/11 15:42:14 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// runs a string until the finalizing \0. Returns the length of s.
// if an empty string is passed, displays an error message and returns -1.
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}
