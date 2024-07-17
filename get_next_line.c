/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:29:42 by antandre          #+#    #+#             */
/*   Updated: 2024/07/17 20:18:38 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



char	*get_next_line(int fd)
{
	static char *saved[];
	int readed;
	char *buffer;

	while (!buffer || !ft_isnewline(buffer))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		//Funcion guardar lo que sobra en saved2
		//Funcion concatenar mas free y allocar nuevo espacio readed
	}
	saved = malloc(readed * sizeof(char));
	if (!saved)
		return (NULL);
		
	//Funcion buscar \n en save
		//True - Funcion leer
		//False - Funcion leer 
}

int	main(void)
{
	int fd;

	fd = open("a", 0_RDONLY);

	while()
	{
		get_next_line(fd);
	}
}
