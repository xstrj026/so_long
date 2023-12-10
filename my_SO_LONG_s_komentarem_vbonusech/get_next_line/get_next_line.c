/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:12:53 by jstrojsa          #+#    #+#             */
/*   Updated: 2023/07/12 15:12:53 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//creates string, but compounds also chars behing \n
char	*get_string(int fd, char *string)
{
	ssize_t	bytes_read;
	char	*buffer;
	char	*sup_string;

	bytes_read = 1;
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0 && ft_strchr(string, '\n') == 0)
	{
		sup_string = string;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		string = ft_strjoin(string, buffer);
		free(sup_string);
	}
	free(buffer);
	return (string);
}
//bytes_read = 1; inicialisation for the first loop, to get inside

//to get the final_line with \n end of the line and 0 zero byte at 
//the end of string
char	*get_the_line(char *string)
{
	char	*final_line;
	int		i;

	i = 0;
	if (!*string)
		return (NULL);
	while (string[i] != '\n' && string[i])
		i++;
	final_line = malloc(sizeof(char) * (i + 2));
	if (!final_line)
		return (NULL);
	i = 0;
	while (string[i] != '\n' && string[i])
	{
		final_line[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		final_line[i] = string[i];
		i++;
	}
	final_line[i] = '\0';
	return (final_line);
}

//function have to return new string(static) withouth 
// the previous rest of the line.
char	*overvrite_static_string(char *string)
{
	char	*new_static;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (string[i] != '\n' && string[i])
		i++;
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	new_static = malloc((ft_strlen(string) - i + 1) * sizeof(char));
	if (!new_static)
		return (NULL);
	i++;
	while (string[i])
		new_static[j++] = string[i++];
	new_static[j] = '\0';
	free(string);
	return (new_static);
}

char	*get_next_line(int fd)
{
	static char	*string = NULL;
	char		*the_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string = get_string(fd, string);
	if (!string)
		return (NULL);
	the_line = get_the_line(string);
	string = overvrite_static_string(string);
	return (the_line);
}
