/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:29:42 by antandre          #+#    #+#             */
/*   Updated: 2024/07/31 13:58:50 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*saved[1024];
	int			readed;
	char		*buffer;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
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
			//TODO Si no hay salto de linea pero readed > 0 printamos saved y borramos saved.
			//TODO Si readed == 0 (EOF) printamos lo que haya en saved (si hay) y borramos saved.
			if (readed == 0)
				return (NULL);
		}
		return (ft_strtrim_jump(&saved[fd]));
	}
	return (NULL);
}
