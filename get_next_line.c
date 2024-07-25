/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:29:42 by antandre          #+#    #+#             */
/*   Updated: 2024/07/25 10:56:50 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved[1024];
	int			readed;
	char		*buffer;

	if (saved[fd] && ft_isnewline(saved[fd]) > 0)
		return (ft_strtrim_jump(&saved[fd]));
	else
	{
		buffer = NULL;
		while (!ft_isnewline(saved[fd]))
		{
			buffer = malloc(BUFFER_SIZE * sizeof(char));
			if (!buffer)
				return (NULL);
			readed = read(fd, buffer, BUFFER_SIZE);
			if (readed > 0)
				readed = ft_strncat(&saved[fd], buffer, readed);
			free(buffer);
			buffer = NULL;
			if (!readed)
				return (NULL);
		}
		return (ft_strtrim_jump(&saved[fd]));
	}
	return (NULL);
}
