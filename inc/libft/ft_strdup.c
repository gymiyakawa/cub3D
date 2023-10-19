/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:43:23 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/10/18 18:12:32 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	if (!s1)
		return (NULL);
	str = x_calloc((ft_strlen(s1) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		str[i] = s1[i];
	}
	str[i] = '\0';
	return (str);
}
