/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:13:29 by raruiz-r          #+#    #+#             */
/*   Updated: 2023/10/10 17:05:15 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    error_and_exit(char *str, t_main *data)
{
    printf("%s\n",str);
    free(data);//fix me a function to free data;
    exit(1);
}