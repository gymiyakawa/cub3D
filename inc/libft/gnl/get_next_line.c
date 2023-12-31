/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:20:26 by raruiz-r          #+#    #+#             */
/*   Updated: 2023/10/19 14:31:04 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*isolate_line(char *keep)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!keep[i])
		return (NULL);
	while (keep[i] && keep[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (keep[i] && keep[i] != '\n')
	{
		line[i] = keep[i];
		i++;
	}
	if (keep[i] == '\n')
	{
		line[i] = keep[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_keep(char *keep)
{
	size_t	i;
	size_t	j;
	char	*clean_keep;

	i = 0;
	j = 0;
	while (keep[i] && keep[i] != '\n')
		i++;
	if (!keep[i])
	{
		free(keep);
		return (NULL);
	}
	clean_keep = ft_calloc(sizeof(char), (ft_strlen(keep) - i));
	if (!clean_keep)
		return (NULL);
	i++;
	while (keep[i])
		clean_keep[j++] = keep[i++];
	clean_keep[j] = '\0';
	free(keep);
	return (clean_keep);
}

char	*get_next_line(int fd)
{
	static char		*keep;
	char			*line;
	int				i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	line = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	i = 1;
	while (!ft_strchrsearch(keep, '\n') && i != 0)
	{
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
		{
			free(line);
			return (NULL);
		}
		line[i] = '\0';
		keep = ft_strjoingnl(keep, line);
	}
	free(line);
	line = isolate_line(keep);
	keep = get_keep(keep);
	return (line);
}
