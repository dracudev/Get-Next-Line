/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:55:56 by antandre          #+#    #+#             */
/*   Updated: 2024/08/01 10:56:00 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <file20>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        int fd = open(argv[i], O_RDONLY);
        char *line = get_next_line(fd);
        if (fd == -1)
        {
            printf("%s", line);
            continue;
        }
        printf("Reading from %s:\n", argv[i]);
        while (1)
        {
            printf("Retrieved line: %s\n", line);
            if (line == NULL)
				break;
			free(line);
			line = NULL;
			line = get_next_line(fd);
        }
		printf("\n");
        printf("Finished reading from %s\n\n", argv[i]);
        close(fd);
    }
    return (0);
}
