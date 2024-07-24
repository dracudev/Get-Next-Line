/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:29:42 by antandre          #+#    #+#             */
/*   Updated: 2024/07/24 18:18:56 by antandre         ###   ########.fr       */
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

int	main(void)
{
	int		fd;
	int		fd2;
	int		x;
	char	*line;

	x = 15;
	fd = open("a", O_RDONLY);
	fd2 = open("b", O_RDONLY);
	while (--x > 0)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = NULL;
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
		line = NULL;
	}
}
