/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:29:42 by antandre          #+#    #+#             */
/*   Updated: 2024/07/30 16:01:11 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*saved[1024];
	int			readed;
	char		*buffer;

	if (fd == -1)
		return (NULL);
	if (saved[fd] && ft_isnewline(saved[fd]) > -1)
		return (ft_strtrim_jump(&saved[fd]));
	else
	{
		buffer = NULL;
		while (ft_isnewline(saved[fd]) == -1)
		{
			buffer = malloc(BUFFER_SIZE * sizeof(char));
			if (!buffer)
				return (NULL);
			readed = read(fd, buffer, BUFFER_SIZE);
			if (readed > 0)
				readed = ft_strncat(&saved[fd], buffer, readed);
			free(buffer);
			buffer = NULL;
			//Si readed == 0 (Es decir fin de archivo EOF) printamos lo que haya en saved (si hay) y borramos saved.
			if (readed == 0)
				return (NULL);
		}
		return (ft_strtrim_jump(&saved[fd]));
	}
	return (NULL);
}
