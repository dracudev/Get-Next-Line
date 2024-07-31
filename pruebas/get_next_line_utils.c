/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:08:42 by antandre          #+#    #+#             */
/*   Updated: 2024/07/31 14:17:11 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_isnewline(char *buffer)
{
	int	i;

	if (!buffer)
		return (-1);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dsize)
{
	size_t	slen;
	size_t	i;

	slen = ft_strlen(src);
	i = 0;
	if (dsize < 1)
		return (slen);
	while (src[i] != '\0' && i < dsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

int	ft_strncat(char **saved, char *buffer, int size)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!(*saved))
		str = malloc((size + 1) * sizeof(char));
	else
		str = malloc(((ft_strlen(*saved) + size) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (*saved && (*saved)[i])
	{
		str[i] = (*saved)[i];
		i++;
	}
	j = 0;
	while (j < size)
		str[i++] = buffer[j++];
	str[i] = '\0';
	if (*saved)
		free(*saved);
	*saved = NULL;
	*saved = str;
	return (1);
}

char	*ft_strtrim_jump(char **saved)
{
	char	*strcut;
	char	*strsaved;
	int		i;
	int		j;

	if (!*saved)
		return (NULL);
	i = 0;
	// Calculate the length of the line to be returned
	while ((*saved)[i] && (*saved)[i] != '\n')
		i++;
	// Include newline if present
	if ((*saved)[i] == '\n')
		i++;
	strcut = malloc((i + 1) * sizeof(char));
	if (!strcut)
		return (NULL);
	ft_strlcpy(strcut, *saved, i); // Copy line to strcut
	strcut[i] = '\0';

	// Prepare the remaining data in saved
	if ((*saved)[i] != '\0')
	{
		strsaved = malloc((ft_strlen(&(*saved)[i]) + 1) * sizeof(char));
		if (!strsaved)
		{
			free(strcut);
			return (NULL);
		}
		j = 0;
		while ((*saved)[i])
			strsaved[j++] = (*saved)[i++];
		strsaved[j] = '\0';
	}
	else
		strsaved = NULL; // No more data left

	free(*saved);
	*saved = strsaved;
	return (strcut);
}
