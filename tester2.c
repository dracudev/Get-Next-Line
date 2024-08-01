/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:45:37 by antandre          #+#    #+#             */
/*   Updated: 2024/08/01 15:25:16 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	//int		fd2;
	int		x;
	char	*line;

	x = 15;
	//fd = open("char1" O_RDONLY);
	fd = 0;
	//fd2 = open("B", O_RDONLY);
	while (--x > 0)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = NULL;
		//line = get_next_line(fd2);
		//printf("%s", line);
		//free(line);
		//line = NULL;
	}
}
