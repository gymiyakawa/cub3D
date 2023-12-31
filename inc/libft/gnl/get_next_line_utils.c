/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:21:34 by raruiz-r          #+#    #+#             */
/*   Updated: 2023/10/11 12:09:33 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	*ft_calloc(size_t count, size_t size)
// {
// 	size_t	i;
// 	char	*call;

// 	i = 0;
// 	if (count == SIZE_MAX && size == SIZE_MAX)
// 		return (NULL);
// 	call = malloc(count * size);
// 	if (!call)
// 		return (NULL);
// 	while (i < count * size)
// 	{
// 		call[i] = 0;
// 		i++;
// 	}
// 	return (call);
// }

char	*ft_strchrsearch(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoingnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*arr;

	if (!s1 && !s2)
		return (NULL);
	arr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		arr[i + j] = s2[j];
		j++;
	}
	arr[i + j] = '\0';
	if (s1)
		free(s1);
	return (arr);
}
