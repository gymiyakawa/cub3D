/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:13:29 by raruiz-r          #+#    #+#             */
/*   Updated: 2023/10/11 10:01:17 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    error_and_exit(char *str, t_main *data)
{
    printf("%s\n",str);
				(void)data; // delete this once free data is functional
	// free(data);//fix me a function to free data;
    exit(1);
}


