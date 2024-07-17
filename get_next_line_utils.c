/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:08:42 by antandre          #+#    #+#             */
/*   Updated: 2024/07/17 17:02:29 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_isnewline(char *buffer)
{
	int i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return(i);
}

void	ft_strncat(char *saved, char *buffer, int buffer_size)
{
	int i;
	int j;
	char *str;

	if (!saved || !buffer)
		return (NULL);	//REVISAR POSIBLES ERRORES
	str = malloc(((ft_strlen(saved) + buffer_size) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (saved[i])
		str[i] = saved[i++];
	j = 0;
	while (j < buffer_size)
		str[i++] = buffer[j++];
	str[i] = '\0';
	if (saved)
		free(saved);
	saved = NULL;
	saved = str;
}
