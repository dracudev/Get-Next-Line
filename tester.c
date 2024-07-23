/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:05:09 by antandre          #+#    #+#             */
/*   Updated: 2024/07/17 13:34:50 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *get_next_line(int fd)
{
	static char *saved[];
	int readed;
	char *buffer;
	

	readed = read(fd, buffer, BUFFER_SIZE);

	saved = malloc(readed * sizeof(char));
	if (!saved)
		return (NULL);
}

int	main(void)
{
	int fd;

	fd = open("a", O_RDONLY);

	while (
	get_next_line(fd);
	get_next_line(fd);





	while (null)
	{
		//comprobar si tenemos guardado un \n en saved
		// si true leemos de **saved, printamos hasta el \n y guardamnos el resto
		//si no, leemos archivo n caracteres (buffer_size) hasta el siguiente \n
		get_next_line();
		
	}
}

buffer_size = 30;

hola mundo
que tal
como estas
tuputamadre
.
(null)
(null)
(null)


hola mundo


que tal


como estas


