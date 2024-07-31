/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:41:16 by antandre          #+#    #+#             */
/*   Updated: 2024/07/31 14:17:23 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

char	*get_next_line(int fd);
int		ft_isnewline(char *buffer);
int		ft_strlen(char *str);
int		ft_strncat(char **saved, char *buffer, int buffer_size);
char	*ft_strtrim_jump(char **saved);
size_t	ft_strlcpy(char *dst, char *src, size_t dsize);

#endif
