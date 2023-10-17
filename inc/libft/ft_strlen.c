/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:58:08 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/10/17 12:58:10 by gmiyakaw         ###   ########.fr       */
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
