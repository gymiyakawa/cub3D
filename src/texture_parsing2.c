/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:34:27 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/11/02 10:35:02 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_remaining_arg(char *arg, int i, t_main *ms)
{
	while (arg[++i])
	{
		if (arg[i] != ' ' && arg[i] != '\n')
			error_and_exit(E_PRS_TXT, ms);
	}
	return ;
}
