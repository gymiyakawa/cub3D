/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:14:54 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/10/25 13:15:13 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	line_count(char *str, t_main *ms)
{
	char	*temp;
	int		i;

	i = 0;
	if (ms->fd < 2)
		ms->fd = open_fd(str, ms);
	temp = "str";
	while (temp)
	{
		i++;
		temp = get_next_line(ms->fd);
		free(temp);
	}
	close(ms->fd);
	return (i);
}

char	**copy_file(char *str, t_main *ms)
{
	char	**file_copy;
	char	*temp;
	int		i;

	i = 0;
	file_copy = ft_calloc(ms->line_count + 1, sizeof(char *));
	if (!file_copy)
		error_and_exit(E_MALLOC, ms);
	ms->fd = open_fd(str, ms);
	temp = get_next_line(ms->fd);
	while (temp != NULL)
	{
		file_copy[i] = ft_strdup(temp);
		i++;
		temp = x_free(temp);
		temp = get_next_line(ms->fd);
	}
	close(ms->fd);
	temp = x_free(temp);
	file_copy[i] = NULL;
	return (file_copy);
}

int	check_input_extension(char *str, t_main *ms)
{
	char	*comp;
	int		i;
	int		j;

	comp = ".cub";
	i = ft_strlen(str) - 1;
	j = 3;
	if (!str)
		error_and_exit(E_MAP, ms);
	while (comp && str && j >= 0)
	{
		if (comp[j] != str[i])
			error_and_exit(E_MAP, ms);
		i--;
		j--;
	}
	return (0);
}

bool	is_valid_line(char *line)
{
	char	**charset;
	int		i;
	int		j;

	charset = make_charset();
	i = 0;
	while (charset[i] != NULL)
	{
		j = -1;
		while (line[++j])
		{
			if (valid_up_to_identifier(&line[0], &line[j]) == false)
				continue ;
			if (ft_strncmp(charset[i], &line[j], ft_strlen(charset[i])) == 0)
			{
				charset = x_free(charset);
				return (true);
			}
		}
		i++;
	}
	charset = x_free(charset);
	return (false);
}
