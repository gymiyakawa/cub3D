/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:18:42 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/10/10 12:25:34 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defs.h"

int main (int ac, char **av) {
	
	(void) ac;
	(void) av;
	
	char *str = {"hello"};
	
	
	printf("%s \n", str);
	
	char *str2 = ft_strdup(str);
	
	printf("%s \n", str2);
	
	return (0);
}