/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:22:21 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/07/08 12:14:13 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strchrsearch(char *s, int c);
char	*ft_strjoingnl(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);

#endif
