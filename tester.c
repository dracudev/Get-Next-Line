/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:55:56 by antandre          #+#    #+#             */
/*   Updated: 2024/07/25 10:56:37 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
