/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:52:20 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/10/17 13:49:44 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// frees every string in the array, and the pointer
	// itself at the end
#include "libft.h"

void	*ft_free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		if (array[i])
		{
			array[i] = x_free(array[i]);
		}
		i++;
	}
	if (array)
		array = x_free(array);
	return (NULL);
}
